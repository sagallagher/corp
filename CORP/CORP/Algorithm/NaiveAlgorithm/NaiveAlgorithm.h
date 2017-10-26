#ifndef _NAIVE_ALGORITHM_GUARD
#define _NAIVE_ALGORITHM_GUARD 1
#include"../Algorithm.h"
#include"../../Cover/Cover.h"


class NaiveAlgorithm : public Algorithm {

public:
	bool run();
	NaiveAlgorithm(Cover& cover);
	NaiveAlgorithm();
	Cover _cover;

private:
	void runHelper(
		Cover cover,
		std::vector<int> solution,
		int currentVertex);
};




#endif 