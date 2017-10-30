#include"NaiveAlgorithm.h"
#include<vector>
#include<algorithm>


// used to display vectors that contain possible solutions
void displaySolution(std::vector<int> solution) {
	std::cout << "solution:\t";
	for (int i : solution) std::cout << i << " ";
	std::cout << std::endl;
}

bool NaiveAlgorithm::run(Cover& cover) {

	// call recursive helper method
	runHelper(cover);

	return true;
}

// return true if an element is a vector
bool inSolution(std::vector<int> solution, int element) {
	return (std::find(solution.begin(), solution.end(), element) != solution.end());
}

void NaiveAlgorithm::runHelper(Cover cover, std::vector<int> solution) {

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

			runHelper(temp_cover, temp_solution);

		// order doesn't matter, don't pursue repetitive solutions and don't pick the same vertex twice
		if (!solution.empty() && vertex <= solution.at(solution.size() - 1)) return;
	}

}

std::vector<std::vector<int>> NaiveAlgorithm::getSolutionSet() { return _solution_set; }

