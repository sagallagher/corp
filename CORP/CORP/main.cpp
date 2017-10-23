#include<iostream>
#include"Config/Config.h"
#include"OptionContainer/OptionContainer.h"
#include"InputParser\InputParser.h"
#include <fstream>
#include <string>
#include"Star\Star.h"
#include"Cover\Cover.h"
#include"Boolset\BoolSet.h"


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

	//UP TO THIS POINT WORKS!!!!!@

	Star dataStar(dataMatrix);

	Cover cover(dataStar);

	//SOLUTIONS TESTED BY HAND AND VERIFIED:
	// 1  2 20 23 24
	// 1  5 19 20 24
	// 1  6 11 13 20
	// 1  8 12 13 19
	// 2  4  5 15 24
	// 2  5  7 12 24
	std::vector<int> solution = {1,2,20,23,24};

	std::cout << cover.toString() << "\n";

	std::cout << "SELECTING SOLUTION\n";
	for (int vertex : solution) 
	{
		cover.selectUnchecked(vertex - 1);
		std::cout << "element selected:\t" << vertex-1 << std::endl;

	}
	
	std::cout << "end of loop\n";
	std::cout << cover.checkCover() << std::endl;
	std::cout << "FACETS COVERED\t" << cover.facetsCovered() << std::endl;
	std::cout << cover._bitVector.length() << "\n";
	std::cout << cover.toString() << "\n";



	return 0;
}
