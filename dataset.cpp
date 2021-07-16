#include "dataset.hpp"

Dataset::Dataset()//it does all the stuff
{
	 // Gives me access to the extraRandom function
	std::stringstream ss;
	int aBadCount;
	float base;
	for(int i=1;i<=4;i++)
	{
		badCount=0;
		ss<<"t"<<i<<".txt"; //gives the file names
		
		input.open(ss.str());
		input>>numBatches>>numItems>>badBatchPercent>>badItemPercent>>sampleSize;
		input.close();
		ss.str("");
		ss.clear();
		std::cout <<std::endl<< "Simulation " <<i<<":"<<std::endl
		<<'\t'<<std::left<<std::setw(50)<<"Number of batches of items:"<<numBatches<<std::endl
		<<'\t'<<std::setw(50)<<"Number of items in each batch"<<numItems<<std::endl
		<<'\t'<<std::setw(50)<<"Percentage of batches containing bad items" << badBatchPercent << std::endl
		<<'\t'<<std::setw(50)<<"Percentage of items that are bad in a bad set" << badItemPercent<< "%"<< std::endl
		<<'\t'<<std::setw(50)<<"Items sampled from each set"<<sampleSize << std::endl <<std::endl;

		base=(100-badItemPercent*1.0)/100;
		generation();// generations the datasets
		aBadCount=montecarlo.analysis(numBatches, numItems, sampleSize); // does montecarlo analysis on the datasets
		std::cout <<std::endl<< "Base = " << base << " exponent = " << sampleSize << std::endl
		<<"P(failure to detect bad batch) = " << pow(base,sampleSize) << std::endl
		<<"Percentage of bad batches actually detected = " <<100-((badCount-aBadCount)*1.0/badCount)*100 << std::endl << std::endl;
	}
	// this following will be for the simulation of Part 2
	int numDays;
	int numCat;
	std::string slRange;
	std::string shRange;
	std::string sprob;
	std::string unit;
	int lRange;
	int hRange;
	int prob;
	int cumulativeInt=0;
	std::vector<int> cumulative;
	std::vector<int> meanRanges;
	float aModel =0;
	input.open("readings.txt");
	input>>numDays>>numCat;
	ss.clear();
	std::cout<<"Simulated days: " <<numDays << std::endl << "Number of categories: "<<numCat << std::endl
	<<"Ranges and occurrences in each range:" << std::endl;
	for(int m=0;m<numCat;m++) // analytical model
	{
		std::getline(input,slRange,'-');
		std::getline(input,shRange,':');
		std::getline(input,sprob);
		ss.str(slRange);
		ss>>lRange;
		ss.clear();
		ss.str(shRange);
		ss>>hRange;
		ss.clear();
		ss.str(sprob);
		ss>>prob;
		ss.clear();
		std::cout<<lRange<<"-"<<hRange<<": "<<prob<<std::endl;
		aModel+=(((lRange+hRange)*1.0)/2)*((prob*1.0)/100);
		cumulativeInt+=prob;
		cumulative.push_back(cumulativeInt);
		meanRanges.push_back((lRange+hRange)/2);


	}
	std::getline(input,unit);
	input.close();
	std::cout<<"Analytical mode: "<< aModel<< ". Expected value is in the 8000-12000/"<< unit<< " range"
	<<std::endl;

	//simulation model
	int rand;
	float sum=0;
	for(int p=0;p<numDays;p++)
	{
		rand=montecarlo.extraRandom()%100;
		for(int q=0; q<numCat; q++)
		{
			if(rand<cumulative.at(q))
			{
				sum+=meanRanges.at(q);
				break;
			}
		}
	}
	sum=sum*1.0/numDays;
	std::cout<<"Simulation: "<<sum<<". Expected value is in the 8000-12000/" <<unit<< " range." << std::endl;
	system("rm ds*");
}

void Dataset::generation()
{

	std::stringstream ss;
	std::cout<<"Generating data sets:" << std::endl<<std::endl;

	for(int i=1;i<=numBatches;i++)
	{
		ss<<"ds"<<i<<".txt";
		output.open(ss.str());
		int totalBad=0;
		if(montecarlo.extraRandom()<=badBatchPercent)//determines if its a bad batch
		{
			std::cout<<"Create bad set batch #"<<i<<",";
			badCount++;

			for(int k=0;k<numItems;k++)
			{
				if(montecarlo.extraRandom()<=badItemPercent)// bad item detected
				{
					output<<"b"<<'\n';
					totalBad++;
				}
				else
				{
					output<<"g"<<'\n';
				}
			}
			std::cout<<" totBad = " << totalBad << " total = " << numItems << " badpct = " <<badItemPercent
			<<std::endl;

		}
		else //write all good
		{
			for(int j=0;j<numItems;j++)
			{
				output<<"g"<<'\n';
			}
		}
		output.close();
		ss.str("");
		ss.clear();

	}
	std::cout<<"Total bad sets = " << badCount << std::endl;

}
