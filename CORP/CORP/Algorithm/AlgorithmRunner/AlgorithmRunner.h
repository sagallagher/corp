#ifndef _ALGORITHM_CONTAINER_GUARD
#define _ALGORITHM_CONTAINER_GUARD 1

#include"../Algorithm.h"
#include "../NaiveAlgorithm/NaiveAlgorithm.h"

class AlgorithmRunner {

public:


	AlgorithmRunner(Algorithm* algorithm_to_run);

	bool start(Cover& cover);

	std::vector<std::vector<int>> getSolutionSet();

	std::string toString();

private:
	Algorithm* _algorithm;
	std::vector<std::vector<int>> _solutions;
};


#endif

// AlgorithmContainer* naive = new AlgorithmContainer(new NaiveAlgorithm);