#include"NaiveAlgorithm.h"
#include<vector>
#include<algorithm>

// the initial cover is taken in the contructor
NaiveAlgorithm::NaiveAlgorithm(Cover& cover) : _cover{ cover } {}

bool NaiveAlgorithm::run() {
	
	// vector to store each individual solution
	std::vector<int> solution = {};

	// vertex to start at
	int currentVertex = 0;

	// call recursive helper method
	runHelper(_cover, solution, currentVertex);

	// return true if a solution was found, false otherwise
	return !_solution_set.empty();
}

// used to display vectors that contain possible solutions
void displaySolution(std::vector<int> solution) {
	std::cout << "solution:\t";
	for (int i : solution) std::cout << i << " ";
	std::cout << std::endl;
}

// find every possible solution
void NaiveAlgorithm::runHelper(Cover cover, std::vector<int> solution, int current_vertex) {

	// if solution size exceeds upper bound, stop exploring that solution
	if (solution.size() > cover._star.upperBound()) return;

	// for each vertex
	while (current_vertex < cover.vertices()) {
		
		// push the vertex to the current solution
		solution.push_back(current_vertex);

		// select the vertex in the current cover
		cover.select(current_vertex);

		// if a solution was found, save it
		if (cover.checkCover()) _solution_set.push_back(solution);
		
		// explore the next vertex, passing a copy of the current solution and cover
		runHelper(cover, solution, ++current_vertex);

	}

}
