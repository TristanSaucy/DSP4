#ifndef MONTECARLO_HPP
#define MONTECARLO_HPP
#include <stdlib.h>
#include <cmath>
#include <string>
#include <time.h>
#include <iostream>
Generating data sets:

Create bad set batch #1, totBad = 45 total = 1000 badpct = 1
Create bad set batch #17, totBad = 54 total = 1000 badpct = 1
Create bad set batch #23, totBad = 51 total = 1000 badpct = 1
Create bad set batch #35, totBad = 48 total = 1000 badpct = 1
Create bad set batch #47, totBad = 45 total = 1000 badpct = 1
Create bad set batch #53, totBad = 72 total = 1000 badpct = 1
Create bad set batch #56, totBad = 54 total = 1000 badpct = 1
Create bad set batch #58, totBad = 42 total = 1000 badpct = 1
Create bad set batch #62, totBad = 51 total = 1000 badpct = 1
Create bad set batch #83, totBad = 61 total = 1000 badpct = 1
Create bad set batch #84, totBad = 51 total = 1000 badpct = 1
Create bad set batch #86, totBad = 46 total = 1000 badpct = 1
Create bad set batch #89, totBad = 55 total = 1000 badpct = 1
Create bad set batch #92, totBad = 61 total = 1000 badpct = 1
Create bad set batch #103, totBad = 62 total = 1000 badpct = 1
Create bad set batch #105, totBad = 53 total = 1000 badpct = 1
Create bad set batch #113, totBad = 56 total = 1000 badpct = 1
Create bad set batch #115, totBad = 51 total = 1000 badpct = 1
Create bad set batch #126, totBad = 63 total = 1000 badpct = 1
Create bad set batch #136, totBad = 54 total = 1000 badpct = 1
Create bad set batch #151, totBad = 63 total = 1000 badpct = 1
Create bad set batch #152, totBad = 62 total = 1000 badpct = 1
Create bad set batch #153, totBad = 53 total = 1000 badpct = 1
Create bad set batch #169, totBad = 61 total = 1000 badpct = 1
Create bad set batch #175, totBad = 39 total = 1000 badpct = 1
Create bad set batch #182, totBad = 65 total = 1000 badpct = 1
Create bad set batch #185, totBad = 52 total = 1000 badpct = 1
Create bad set batch #191, totBad = 44 total = 1000 badpct = 1
Create bad set batch #196, totBad = 50 total = 1000 badpct = 1
Create bad set batch #199, totBad = 54 total = 1000 badpct = 1
Total bad sets = 30


Analyzing Data Sets:
batch #1 is bad
batch #17 is bad
batch #35 is bad
batch #47 is bad
batch #53 is bad
batch #58 is bad
batch #62 is bad
batch #84 is bad
batch #92 is bad
batch #105 is bad
batch #113 is bad
batch #152 is bad
batch #169 is bad
batch #175 is bad
batch #185 is bad
batch #191 is bad
batch #199 is bad

Base = 0.99 exponent = 10
P(failure to detect bad batch) = 0.904382
Percentage of bad batches actually detected = 56.6667

Simulated days: 100
Number of categories: 7
Ranges and occurrences in each range:
0-2000: 15
2000-4000: 25
4000-8000: 20
8000-12000: 15
12000-18000: 10
18000-24000: 10
24000-28000: 5
Analytical mode: 8500. Expected value is in the 8000-12000/ml range
Simulation: 8940. Expected value is in the 8000-12000/ml range.
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
class MonteCarlo
{
	public:
		int extraRandom();
		int analysis(int numBatches,int numItems,int sampleSize);
		char charGet(std::ifstream& cGet, int rand);
	private:
};
#endif
