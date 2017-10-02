#include<iostream>
#include"Config/Config.h"
#include"OptionContainer/OptionContainer.h"
#include <fstream>
#include <string>

Config* Config::_instance = 0;

int main(int argc, char const *argv[]) {

	Config::initialize(argc, argv);

	//Open file stream for data
	std::ifstream _is;

	//How to correctly define input file?
	std::string inputData = Config::getInstance()->pull("AdjacencyList","DefualtAdjacencyList");
	_is.open(inputData);

	if (!_is)
	{
		std::cerr << "Unable to open file " << inputData << "for reading.";
		return 1;
	}

	//End of file stream

	return 0;
}
