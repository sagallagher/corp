#ifndef _INPUT_PARSER
#define _INPUT_PARSER


//Should InputParser contain OptionContainer.h, or is it instead called in OptionContainer ? 
#include "OptionContainer.h"
#include "Matrix.h"

#include <iostream>
#include <fstream>
#include <string>

//Given input file name by OptionContainer, 'input.txt' for instance.

class InputParser
{
	public:

		InputParser(std::istream& in) : _is{ in }
		{
		}

		virtual ~InputParser()
		{
			//Closing input file
			_is.close();
		}


	protected:
		std::istream& _is;


		//In main
		ifstream _is;
		_is.open(inputData);

if (!_is)
{
	std::cerr << "Unable to open file " << name << "for reading.";
	return 1;
}
// In main



	Matrix* parse()
	{
		int rows, columns;
		_is >> rows;
		_is >> columns;


		//create a Matrix object from Matrix.h
		Matrix dataMatrix = new Matrix(rows, columns);

		//Stores all values from input file into the Matrix object
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				int temp;
				_is >> temp;

				//Use a Set() function from Matrix.h to store the values
				dataMatrix.set(i, j, temp);
			}
		}


		//Successful completion, return Matrix object
		return dataMatrix;

	}
};
#endif