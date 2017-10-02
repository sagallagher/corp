#ifndef _ALGORITHM_CONTAINER_
#define _ALGORITHM_CONTAINER_ 1

#include"Algorithm.h"

class AlgorithmContainer {
public:
	AlgorithmContainer(Algorithm*);
	void repair();

private:
	Algorithm* _algorithm;
};


#endif