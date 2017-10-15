#include "InputParser.h"
#include<sstream>

InputParser::InputParser(std::istream& in) : _is{ in }
{
	std::cout << "CONSTRUCTED INPUT PARSER\n";
	parse();
}

InputParser::~InputParser()
{

}

int InputParser::getRowCount() {
	std::string str;
	int rows = 0;
	while (std::getline(_is, str)) {
		rows++;
	}
	return rows;
}

int InputParser::getColumnCount() {
	std::string line;
	std::getline(_is,line);
	std::istringstream ss(line);
	int num;
	int cols = 0;
	while (ss >> num) {
		cols++;
	}
	return cols;
}

//Stores all values from input file into the Matrix object
void InputParser::parse() {
	_dataMatrix = Matrix<int>(getRowCount(),getColumnCount());
	std::cout << "PARSING\n";
	int i = 0, j = 0;
	std::string str;
	while (std::getline(_is, str))
	{
		std::istringstream ss(str);
		std::cout << "made string stream\n";
		int num;
		std::cout << "looping through row\n";
		// loop through each int in the line
		while (ss >> num)
		{
			std::cout << "looped once\n";
			// append that int to "row" vector; num-1 because index starts at 0
			_dataMatrix.set(num, i, j);
			std::cout << "set an item of data matrx " << i << "\t" << j << std::endl;
			j++;
		}
		i++;
		
	}

}

Matrix<int> InputParser::getMatrix()
{
	return _dataMatrix;
}