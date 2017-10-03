#include "InputParser.h"
//Does anything need to be included here? Should it be included in InputParser.h instead?


InputParser::InputParser(std::istream& in) : _is{ in }
{

}

InputParser::~InputParser()
{

}

InputParser::Matrix<int>* parse()
{
	
	int rows, columns;
	_is >> rows;
	_is >> columns;


	//create a Matrix object from Matrix.hpp
	Matrix<int>* dataMatrix = new Matrix<int>(rows, columns);

	//Stores all values from input file into the Matrix object
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			int temp;
			_is >> temp;

			//Use Set() function from Matrix.h to store the values
			dataMatrix.set(temp, i, j);
		}
	}


	//Successful completion, return Matrix object
	return dataMatrix;

}