#include<iostream>
#include"Config/Config.h"
#include"OptionContainer/OptionContainer.h"
#include"InputParser\InputParser.h"
#include <fstream>
#include <string>



int main(int argc, char const *argv[]) {

	const std::string DEFAULT_INPUT = "../../../data/24cell_facets.txt";

	Config::initialize(argc, argv);

	//Open file stream for data
	std::ifstream is;

	std::string inputData = Config::getInstance()->pull("AdjacencyList",DEFAULT_INPUT);
	std::cout << "inputData:\t" << inputData << std::endl;
	is.open(inputData);
	std::cout << "Data file opened\n";
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


	std::cout << "geting the parsed dataMatrix\n";
	Matrix<int>* dataMatrix = parser.getMatrix();
	std::cout << "got the parsed data matrix\n";

	std::cout << "geting string\n";
	std::string dm = dataMatrix->toString();
	std::cout << "displaying outcome\n";
	std::cout << dataMatrix->toString() << std::endl;

	

	return 0;
}
