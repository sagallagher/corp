#include "InputParser.h"
#include<sstream>

InputParser::InputParser(std::ifstream& in) : _is{ in }
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
		std::cout << "looped\n";
		rows++;
	}
	return rows+1;
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
	return cols+1;
}

//Stores all values from input file into the Matrix object
void InputParser::parse() {
	std::cout << "making matrix with correct dimensions\n";
	int cols = getColumnCount();
	int rows = getRowCount();

	// this can be replaced with overloaded = operator
	_dataMatrix = new Matrix<int>(rows, cols);
	_dataMatrix->setRows(rows);
	_dataMatrix->setCols(cols);


	std::cout << "PARSING\n";
	int i = 0, j = 0;
	std::string str;
	_is.clear();
	_is.seekg(0, std::ios::beg);
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
			_dataMatrix->set(num-1, i, j);
			std::cout << "set an item of data matrx " << i << "\t" << j <<  "\t" << num << std::endl;
			j++;
		}
		i++;
		j = 0;
		
	}

}

Matrix<int>* InputParser::getMatrix()
{
	return _dataMatrix;
}