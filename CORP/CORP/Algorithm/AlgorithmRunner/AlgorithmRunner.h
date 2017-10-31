#ifndef _ALGORITHM_CONTAINER_GUARD
#define _ALGORITHM_CONTAINER_GUARD 1

#include"../Algorithm.h"
#include "../NaiveAlgorithm/NaiveAlgorithm.h"

class AlgorithmRunner {

public:


	AlgorithmRunner(Algorithm* algorithm_to_run);

	void repair(Cover& cover);

	bool start();


private:
	Algorithm* _algorithm;
	Cover _cover;
};


#endif

// AlgorithmContainer* naive = new AlgorithmContainer(new NaiveAlgorithm);