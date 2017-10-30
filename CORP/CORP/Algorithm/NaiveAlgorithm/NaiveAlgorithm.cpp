#include"NaiveAlgorithm.h"
#include<vector>
#include<algorithm>

// the initial cover is taken in the contructor
NaiveAlgorithm::NaiveAlgorithm(Cover& cover) : _cover{ cover } 
{
	testInt = 0;
}

NaiveAlgorithm::NaiveAlgorithm() 
{
	testInt = 0;
}


// used to display vectors that contain possible solutions
void displaySolution(std::vector<int> solution) {
	std::cout << "solution:\t";
	for (int i : solution) std::cout << i << " ";
	std::cout << std::endl;
}


bool NaiveAlgorithm::run() {
	
	// vector to store each individual solution
	std::vector<int> solution = {};


	// call recursive helper method
	runHelper(_cover, solution);


	return true;
}

std::vector<int> NaiveAlgorithm::sarahTestRun(Cover &testCover, int startIndex)
{
	int currentVertex = startIndex;
	//continue to loop until the cover is valid
	while (!testCover.checkCover())
	{
		std::cout << "Sarah's Algorithm state of cover: " << testCover.facetsCovered() << " of " << testCover.facets() << " facets covered.\n";
		//loop to 0 if the vertex goes out of bounds
		if (currentVertex >= testCover.vertices() || currentVertex < 0)
			currentVertex = 0;
		//select the current vertex
		testCover.select(currentVertex);
		std::cout << "Sarah's Algorithm is adding vertex " << currentVertex << " to the solution.";
		std::cout << "Current cover:" << testCover._facetVector.toString() << "\n";

		//incriment the vertex
		currentVertex++;
	}

	//vector to contain selected vertices
	std::vector<int> results;
	std::string vertexList = "";
	//populate result vector
	for (int i = 0; i < testCover.vertices(); i++)
	{
		if (testCover._bitVector[i])
		{
			results.push_back(i);
			vertexList.append(" " + std::to_string(i));
		}
	}
	std::cout << "Sarah's Algorithm produced solution:" << vertexList << "\n";
	std::cout << "Is this a solution? : " << testCover.checkCover() << "\n";
	return results;

}

/*
// find every possible solution
void NaiveAlgorithm::runHelper(Cover cover, std::vector<int> solution, int current_vertex) {

	// if solution size exceeds upper bound, stop exploring that solution
	if (solution.size() > cover._star.upperBound()) return;



	// for each vertex
	while (current_vertex < cover.vertices()) {

		// if a solution was found, save it
		if (cover.checkCover()) {
			_solution_set.push_back(solution);
			return;
		}

		// push the vertex to the current solution
		solution.push_back(current_vertex);

		// select the vertex in the current cover
		cover.select(current_vertex);

		displaySolution(solution);

		// explore the next vertex, passing a copy of the current solution and cover
		return runHelper(cover, solution, ++current_vertex);

	}
}

*/

bool inSolution(std::vector<int> solution, int element) {
	return (std::find(solution.begin(), solution.end(), element) != solution.end());
}

void NaiveAlgorithm::runHelper(Cover cover, std::vector<int> solution) 
{
	testInt++;
	//Check solution
	//std::cout << "recurse # " << testInt << " solution: ";
	//displaySolution(solution);

	//std::cout << "IS THIS A SOLUTION???? Results say: " << cover.checkCover() << "!!!!\n";
	//std::cout << "FACETS COVERED: " << cover._facetVector.toString() << "\n";
	
	if (testInt % 100000 == 0) std::cout << testInt << std::endl;
	if (solution.size() > 5) return;
	
	if (cover.checkCover())
	{
		//if solution is valid
		//add it to the list of solutions
		//if (testInt % 100000 == 0) {
	//	std::cout << "*********************************\n";
	//	std::cout << "  SOLUTION FOUND ON RECURSE " << testInt << "\n";
	//	std::cout << "*********************************\n";
		displaySolution(solution);
		_solution_set.push_back(solution);
		//}
		//then return
		return;
	}


	
	//loop through every vertex in the cover
	//std::cout << "looping through vertices...\n";
	for (int vertex = 0; vertex < cover.vertices(); vertex++)
	{

		Cover temp_cover(cover);
		std::vector<int> temp_solution = solution;

		if (!inSolution(solution, vertex))
		{
			

			//std::cout << "current ";
			//displaySolution(solution);
			//std::cout << "Selecting vertex " << vertex << "\n";
			temp_solution.push_back(vertex);
			temp_cover.select(vertex);
			runHelper(temp_cover, temp_solution);
		}

		

	}
	return;
	//if i is not contained in solution
		//call runHelper(cover, solution.push_back(i))

}


std::vector<std::vector<int>> NaiveAlgorithm::getSolutionSet() { return _solution_set; }

