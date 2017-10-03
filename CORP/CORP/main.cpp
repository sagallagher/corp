#include<iostream>
#include"Config/Config.h"
#include"OptionContainer/OptionContainer.h"
#include <fstream>
#include <string>

int main(int argc, char const *argv[]) {

	Config::initialize(argc, argv);

	//Open file stream for data
	std::ifstream _is;

	//How to correctly define input file?
	std::string inputData = Config::getInstance()->pull("AdjacencyList",static_cast<std::string>("../../data/24cell_facets.txt"));
	_is.open(inputData);

	if (!_is)
	{
		std::cerr << "Unable to open file " << inputData << "for reading.";
		return 1;
	}

	//End of file stream

	return 0;
}
