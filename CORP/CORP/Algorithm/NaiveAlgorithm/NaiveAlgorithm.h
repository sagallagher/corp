#ifndef _NAIVE_ALGORITHM_GUARD
#define _NAIVE_ALGORITHM_GUARD 1
#include"../Algorithm.h"
#include"../../Cover/Cover.h"
#include<vector>
#include<string>
#include<iostream>

class NaiveAlgorithm : public Algorithm {

public:
	bool run();
	std::vector<int> sarahTestRun(int startIndex = 0);
	NaiveAlgorithm(Cover& cover);
	Cover _cover;
	std::vector<std::vector<int>> getSolutionSet();
	std::string getSolutionSetToString();
private:
	void runHelper(
		Cover cover,
		std::vector<int> solution,
		int currentVertex);
};




#endif 