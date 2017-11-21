#ifndef _NAIVE_ALGORITHM_GUARD
#define _NAIVE_ALGORITHM_GUARD 1
#include"../Algorithm.h"
#include"../../Cover/Cover.h"
#include<vector>
#include<string>
#include<iostream>
#include"../../Config/Config.h"

class NaiveAlgorithm : public Algorithm {

public:
	std::vector<std::vector<int>> run(Cover& cover, Config* config);

private:
	void runHelper(
		Cover cover,
		std::vector<std::vector<int>>& _solution_set,
		std::vector<int> solution = {});
};




#endif 