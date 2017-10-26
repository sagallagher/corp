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

int main(int argc, char const *argv[]) {

	const std::string DEFAULT_INPUT = "../../../data/24cell_facets.txt";
	const std::string DEFAULT_SOLUTION_SET = "../../../data/24cell_corelist.txt";

	Config::initialize(argc, argv);

	//Open file stream for data
	std::ifstream is;

	std::string inputData = Config::getInstance()->pull("AdjacencyList",DEFAULT_INPUT);

	is.open(inputData);


	if (!is)
	{
		std::cerr << "Unable to open file " << inputData << " for reading.";
		return 1;
	}

	//Create InputParser object
	InputParser parser(is);
	std::cout << "Data file parsed\n";

	//End of file stream
	is.close();

	Cover cover(Star(parser.getMatrix()));

	std::cout << "***CHECKING SOLUTIONS***" << std::endl;

	std::cout << checkSolutions(cover, Config::getInstance()->pull("SolutionSet", DEFAULT_SOLUTION_SET));
	std::vector<int> solution = { 1,2,3,4,5 };
	std::cout << checkSolution(cover, solution);



	
	Cover naive_cover(Star(parser.getMatrix()));
	NaiveAlgorithm alg(naive_cover);

	std::cout << "\nRUNNING NAIVE ALGORITHM\n";
	alg.run();

	std::cout << "result:\t" << alg.run() << std::endl;

	std::cout << "updated\n";
	


	return 0;
}




//SOLUTIONS TESTED BY HAND AND VERIFIED:
// 1  2 20 23 24
// 1  5 19 20 24
// 1  6 11 13 20
// 1  8 12 13 19
// 2  4  5 15 24
// 2  5  7 12 24