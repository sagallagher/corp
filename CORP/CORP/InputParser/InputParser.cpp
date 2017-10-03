#include "InputParser.h"
//Does anything need to be included here? Should it be included in InputParser.h instead?


InputParser::InputParser(std::istream& in) : _is{ in }
{

}

virtual InputParser::~InputParser()
{
	//Closing input file
	_is.close();
}

InputParser::Matrix* parse()
{
	
	int rows, columns;
	_is >> rows;
	_is >> columns;


	//create a Matrix object from Matrix.hpp
	template <typename T> dataMatrix = new Matrix(rows, columns);

	//Stores all values from input file into the Matrix object
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			int temp;
			_is >> temp;

			//Use a Set() function from Matrix.h to store the values
			dataMatrix.set(temp, i, j);
		}
	}


	//Successful completion, return Matrix object
	return dataMatrix;

}