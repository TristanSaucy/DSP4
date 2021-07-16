#ifndef DATASET_HPP
#define DATASET_HPP
#include <string>
#include "montecarlo.hpp"
class Dataset
{
	public:
		Dataset();
		void generation(); 
	private:
		int numBatches;
		int numItems;
		int badBatchPercent;
		int badItemPercent;
		int sampleSize;
		int badCount;
		std::ifstream input;
		std::ofstream output;
		MonteCarlo montecarlo;
};
#endif
