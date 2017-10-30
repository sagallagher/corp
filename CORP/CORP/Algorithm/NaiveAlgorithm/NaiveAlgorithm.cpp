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


bool inSolution(std::vector<int> solution, int element) {
	return (std::find(solution.begin(), solution.end(), element) != solution.end());
}

void NaiveAlgorithm::runHelper(Cover cover, std::vector<int> solution) 
{

	// we know min solution for 24cell is no greater than 5, so don't check past there
	if (solution.size() > 5) return;
	
	// if we found a solution, save it to _solution_set
	if (cover.checkCover())
	{
		_solution_set.push_back(solution);
		// kill this branch because every solution following will be a solution of greater length
		return;
	}

	// for each vertex, go to every other vertex
	for (int vertex = cover.vertices()-1; vertex >= 0 ; vertex--)
	{
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

