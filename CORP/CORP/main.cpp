#include<iostream>
#include"Config/Config.h"
#include"OptionContainer/OptionContainer.h"
#include <fstream>
#include <string>

int main(int argc, char const *argv[]) {

	Config::initialize(argc, argv);

	//Open file stream for data
	std::ifstream is;

	std::string inputData = Config::getInstance()->pull("AdjacencyList",static_cast<std::string>("../../data/24cell_facets.txt"));
	is.open(inputData);

	if (!is)
	{
		std::cerr << "Unable to open file " << inputData << "for reading.";
		return 1;
	}

	//Create InputParser object


	//End of file stream
	is.close();

	return 0;
}
