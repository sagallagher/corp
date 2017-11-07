#define _CRTDBG_MAP_ALLOC
#include<iostream>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif


#include"AlgorithmRunner.h"


AlgorithmRunner::AlgorithmRunner(Algorithm* algorithm_to_run) : _algorithm { algorithm_to_run } {}


bool AlgorithmRunner::start(Cover& cover) {
	return _algorithm->run(cover);
}

std::vector<std::vector<int>> AlgorithmRunner::getSolutionSet() {
	// increment all vertices by 1 before returning the solution set
	std::vector<std::vector<int>> result = _solutions;

	for (std::vector<int> solution : result)
		for (int vertex : solution) vertex++;

	return result;
}

std::string AlgorithmRunner::toString() {

	std::string result = "";

	for (std::vector<int> solution : getSolutionSet())
	{
		for (int vertex : solution)
		{
			result += (std::to_string(vertex) + " ");
		}
		result += "\n";
	}

	return result;
}


