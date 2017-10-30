#ifndef _NAIVE_ALGORITHM_GUARD
#define _NAIVE_ALGORITHM_GUARD 1
#include"../Algorithm.h"
#include"../../Cover/Cover.h"
#include<vector>
#include<string>
#include<iostream>

class NaiveAlgorithm : public Algorithm {

public:
	bool run(Cover& cover);
	std::vector<std::vector<int>> getSolutionSet();

private:
	void runHelper(
		Cover cover,
		std::vector<int> solution = {});
};




#endif 