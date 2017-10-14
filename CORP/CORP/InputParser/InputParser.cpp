#include "InputParser.h"

InputParser::InputParser(std::istream& in) : _is{ in }
{
	parse();
}

InputParser::~InputParser()
{

}

InputParser::InputParser(std::istream& in) : _is{ in } {}

//Stores all values from input file into the Matrix object
void InputParser::parse()
{	
	int rows, columns;
	_is >> rows;
	_is >> columns;
		
	for (unsigned i = 0; i < rows; i++)
	{
		for (unsigned j = 0; j < columns; j++)
		{
			int temp;
			_is >> temp;
			_dataMatrix.set(temp, i, j);
		}
	}
}

Matrix<int> InputParser::getMatrix()
{
	return _dataMatrix;
}