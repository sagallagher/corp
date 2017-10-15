#ifndef _NAIVE_ALGORITHM_GUARD
#define _NAIVE_ALGORITHM_GUARD 1
#include"../Algorithm.h"
#include"../../Matrix/matrix.hpp"

class NaiveAlgorithm : Algorithm {
public:
	NaiveAlgorithm();
	virtual bool run(std::Matrix<int>());

};




#endif 