#ifndef _ALGORITHM_CONTAINER_GUARD
#define _ALGORITHM_CONTAINER_GUARD 1

#include"../Algorithm.h"
#include "../NaiveAlgorithm/NaiveAlgorithm.h"

class AlgorithmRunner {

public:
	AlgorithmRunner(Algorithm* algorithm_to_run);
	// run the algorithm provided in the constructor with the given cover
	bool start(Cover& cover);
	// get 2d vector representation of solution set
	std::vector<std::vector<int>> getSolutionSet();
	// get string representation of solution set
	std::string toString();
	// output toString to a text file
	void write(std::string file_path);


private:
	Algorithm* _algorithm;
	std::vector<std::vector<int>> _solutions;
};


#endif

// AlgorithmContainer* naive = new AlgorithmContainer(new NaiveAlgorithm);