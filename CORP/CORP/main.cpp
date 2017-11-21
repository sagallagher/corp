#define _CRTDBG_MAP_ALLOC
#include<iostream>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif


#include<iostream>
#include"Config/Config.h"
#include"OptionContainer/OptionContainer.h"
#include"InputParser\InputParser.h"
#include <fstream>
#include <string>
#include"Star\Star.h"
#include"Cover\Cover.h"
#include"Boolset\BoolSet.h"
#include<sstream>
#include"Algorithm\NaiveAlgorithm\NaiveAlgorithm.h"
#include<vector>
#include"Algorithm\AlgorithmSelect\AlgorithmSelect.h"
#include"Algorithm\Algorithm.h"


bool checkSolution(Cover& cover, std::vector<int> solution) {
	for (int vertex : solution) cover.selectUnchecked(vertex - 1);

	return cover.checkCover();
}

bool checkSolutions(Cover& cover, std::string solutions_file) {
	std::ifstream solutions(solutions_file);

	std::string line;
	std::vector<int> solution;
	bool allTrue = true;

	while (std::getline(solutions, line)) {
		std::istringstream ss(line);
		int num;
		while (ss >> num) {
			solution.push_back(num);
		}
		if (!checkSolution(cover, solution)) {
			std::cerr << "The Following Solution Failed:\n";
			for (int num : solution) { std::cout << num << " "; }
			std::cout << std::endl;
			allTrue = false;
		}
	}


	solutions.close();
	return allTrue;
}

void printCover(Cover& cov)
{
	std::cout << "Matrix: \n" << cov._star._matrix.toString() << "\n";
	std::cout << "Vertex list: " << cov._bitVector.toString() << "\n";
	std::cout << "Facet list: " << cov._facetVector.toString() << "\n";
	std::cout << "Facets covered: " << cov.facetsCovered() << "\n";
	std::cout << "Is cover?: " << cov.checkCover() << "\n";
	std::cout << "Percent Covered: " << cov.checkCover() << "\n";
}

int main(int argc, char const *argv[]) {

	const std::string DEFAULT_INPUT = "../../data/24cell_facets.txt";
	const std::string DEFAULT_SOLUTION_SET = "../../data/24cell_corelist.txt";

	if (!Config::initialize(argc, argv)) {
		std::cout << "Config file could be parsed" << std::endl;
		return -1;
	}

	//Open file stream for data
	std::ifstream is;

	// store the path to the file containing the adjacency matrix
	std::string inputData = Config::getInstance()->pull("AdjacencyList",DEFAULT_INPUT);

	// use the input file stream to open that file
	is.open(inputData);

	// return -1 if the input file could not be opened
	if (!is) {
		std::cout << "Unable to open file " << inputData << " for reading.";
		system("pause");
		return -1;
	}

	// send the input file stream to an InputParser object to parse the data 
	InputParser parser(is);
	std::cout << "Data file parsed\n";
	//End of file stream
	is.close();
	
	Matrix<int> data_matrix = parser.getMatrix();

	Star star(data_matrix);

	Cover cover(star);
	// create an environment for an algorithm to be selected
	AlgorithmSelect algorithm_select(cover);

	// choose an algorithm and display the solution set
	std::cout << algorithm_select.selectAlgorithm("NaiveAlgorithm").toString();
	
	std::cout << "Dumping Memory Leaks" << std::endl;
	
	_CrtDumpMemoryLeaks();

}