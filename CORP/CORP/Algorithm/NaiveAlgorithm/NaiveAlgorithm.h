#ifndef _NAIVE_ALGORITHM_GUARD
#define _NAIVE_ALGORITHM_GUARD 1
#include"../Algorithm.h"
#include"../../Cover/Cover.h"


class NaiveAlgorithm : public Algorithm {

public:
	bool run();
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