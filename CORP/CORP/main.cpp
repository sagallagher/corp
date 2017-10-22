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

	//4 6 10 15 21 
	std::vector<int> solution = { 4,6,10,15,21};

	for (int i = 0; i < solution.size(); i++) 
	{
		cover.select(solution[i]);
		std::cout << "element selected:\t" << solution[i] << std::endl;
	}

	//std::cout << "Facets covered: " << cover.facetsCovered() << "out of " << cover.facets() << "\n";
	//std::cout << cover.checkCover() << std::endl;

	return 0;
}
