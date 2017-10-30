#include"Algorithm.h"

std::string Algorithm::toString() {

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

std::vector<std::vector<int>> Algorithm::getSolutionSet() { return _solution_set; }