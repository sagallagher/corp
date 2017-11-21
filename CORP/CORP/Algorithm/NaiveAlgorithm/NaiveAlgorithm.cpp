#define _CRTDBG_MAP_ALLOC
#include<iostream>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

#include"NaiveAlgorithm.h"
#include"../../Config/Config.h"
#include<vector>
#include<algorithm>

std::vector<std::vector<int>> NaiveAlgorithm::run(Cover& cover, Config* config) {
	std::vector<std::vector<int>> solution_set;
	// call recursive helper method
	runHelper(cover, solution_set);

	return solution_set;
}

// return true if an element is a vector
bool inSolution(std::vector<int> solution, int element) {
	return (std::find(solution.begin(), solution.end(), element) != solution.end());
}

void NaiveAlgorithm::runHelper(Cover cover, std::vector<std::vector<int>>& _solution_set, std::vector<int> solution) {

	// we know min solution for 24cell is no greater than 5, so don't check past there
	if (solution.size() > 5) return;
	
	// if we found a solution, save it to _solution_set
	if (cover.checkCover()) {
		_solution_set.push_back(solution);
		// kill this branch because every solution following will be a solution of greater length
		return;
	}

	// for each vertex, go to every other vertex
	for (int vertex = cover.vertices()-1; vertex >= 0 ; vertex--) {
		// create a temporary cover and solution set for each branch
		Cover temp_cover(cover);
		std::vector<int> temp_solution = solution;

		// push the current node to the solution
		temp_solution.push_back(vertex);
		// turn on the current vertex in the cover
		temp_cover.select(vertex);

		runHelper(temp_cover,_solution_set, temp_solution);

		// order doesn't matter, don't pursue repetitive solutions and don't pick the same vertex twice
		if (!solution.empty() && vertex <= solution.at(solution.size() - 1)) return;
	}

}



