#ifndef _NAIVE_ALGORITHM_GUARD
#define _NAIVE_ALGORITHM_GUARD 1
#include"../Algorithm.h"
#include"../../Cover/Cover.h"
#include<vector>
#include<string>
#include<iostream>

class NaiveAlgorithm : public Algorithm {

public:
	int testInt;
	bool run();
	std::vector<int> sarahTestRun(Cover &testCover, int startIndex = 0);
	NaiveAlgorithm(Cover& cover);
	NaiveAlgorithm();
	Cover _cover;
	std::vector<std::vector<int>> getSolutionSet();

private:
	void runHelper(
		Cover cover,
		std::vector<int> solution);
};




#endif 