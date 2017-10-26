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

std::vector<int> NaiveAlgorithm::sarahTestRun(int startIndex = 0)
{
	int currentVertex = startIndex;
	//continue to loop until the cover is valid
	while (!_cover.checkCover())
	{
		std::cout << "Sarah's Algorithm state of cover: " << _cover.facetsCovered() << " of " << _cover.facets() << " facets covered.\n";
		//loop to 0 if the vertex goes out of bounds
		if (currentVertex >= _cover.vertices() || currentVertex < 0)
			currentVertex = 0;
		//select the current vertex
		_cover.select(currentVertex);
		std::cout << "Sarah's Algorithm is adding vertex " << currentVertex << " to the solution.";

		//incriment the vertex
		currentVertex++;
	}

	//vector to contain selected vertices
	std::vector<int> results;
	std::string vertexList = "";
	//populate result vector
	for (int i = 0; i < _cover.vertices; i++)
	{
		if (_cover._bitVector[i])
		{
			results.push_back(i);
			vertexList.append(" " + std::to_string(i));
		}
	}
	std::cout << "Sarah's Algorithm produced solution:" << vertexList << "\n";
	return results;

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
