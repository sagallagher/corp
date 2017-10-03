#ifndef _ALGORITHM_CONTAINER_
#define _ALGORITHM_CONTAINER_ 1

#include"../Algorithm/Algorithm.h"

class AlgorithmRunner {
public:
	AlgorithmRunner(Algorithm*);
	void repair();

private:
	Algorithm* _algorithm;
};


#endif

// AlgorithmContainer* naive = new AlgorithmContainer(new NaiveAlgorithm);