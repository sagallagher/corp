#include<iostream>
#include"Config/Config.h"
#include"OptionContainer/OptionContainer.h"
#include"InputParser\InputParser.h"
#include <fstream>
#include <string>




int main(int argc, char const *argv[]) {
	const std::string DEFAULT_INPUT = "../../data/24cell_facets.txt";

	Config::initialize(argc, argv);

	//Open file stream for data
	std::ifstream is;

	std::string inputData = Config::getInstance()->pull("AdjacencyList",DEFAULT_INPUT);
	is.open(inputData);

	if (!is)
	{
		std::cerr << "Unable to open file " << inputData << "for reading.";
		return 1;
	}

	//Create InputParser object
	InputParser parser(is);

	Matrix<int> dataMatrix = parser.getMatrix();

	std::cout << dataMatrix << std::endl;

	//End of file stream
	is.close();

	return 0;
}
