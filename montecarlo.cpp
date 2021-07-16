#include "montecarlo.hpp"

int MonteCarlo::extraRandom() // this makes extra random numbers by introducing noise from the clock
{
	return std::rand()*clock()%100;
}

int MonteCarlo::analysis(int numBatches, int numItems, int sampleSize)
{
	std::cout << std::endl << std::endl << "Analyzing Data Sets:" << std::endl;
	int aBadCount=0;
	std::stringstream ss;
	std::ifstream cGet;
	char tchar;
	int toggle=0;
	for(int i=1; i<=numBatches;i++)
	{
		toggle=0;
		ss<<"ds"<<i<<".txt";
		cGet.open(ss.str());
		for(int j=0;j<=sampleSize;j++)
		{
			tchar = charGet(cGet, extraRandom()%numItems);
			if(tchar=='g')
			{
				continue;
			}
			else if(tchar=='b')
			{
				toggle=1;
				break;
			}
			else
			{
				std::cout << "ERROR";
			}


		}
		if(toggle==1)
		{
		std::cout<<"batch #"<<i<<" is bad"<<std::endl;
		aBadCount++;
		}

		cGet.close();
		ss.str("");
		ss.clear();

	}
	return aBadCount;
}

char MonteCarlo::charGet(std::ifstream& cGet, int rand)
{
	cGet.seekg(rand, std::ios_base::beg);
	char tchar;
	cGet>>tchar;
	return tchar;
}
