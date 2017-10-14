#include "InputParser.h"
//Does anything need to be included here? Should it be included in InputParser.h instead?


InputParser::InputParser(std::istream& in) : _is{ in }
{
	parse();
}

InputParser::~InputParser()
{

}

void InputParser::parse()
{	
	int rows, columns;
	_is >> rows;
	_is >> columns;
	
	//Stores all values from input file into the Matrix object
	for (unsigned i = 0; i < rows; i++)
	{
		for (unsigned j = 0; j < columns; j++)
		{
			int temp;
			_is >> temp;

			//Use Set() function from Matrix.h to store the values
			_dataMatrix.set(temp, i, j);
		}
	}
}

Matrix<int> InputParser::getMatrix()
{
	return _dataMatrix;
}