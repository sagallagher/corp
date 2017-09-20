#ifndef _InputParser_
#define _InputParser_


//Should InputParser contain OptionContainer.h, or is it instead called in OptionContainer ? 
#include "OptionContainer.h"
#include "Matrix.h"

#include <iostream>
#include <fstream>
#include <string.h>

//Given input file name by OptionContainer, 'input.txt' for instance.

class InputParser
{
	public:
	//Says explicit type is missing -- Need to define what type of variable/object the function returns?  Presumably returns a Matrix object?
	ParseInput(std::string inputData)
	{
		//why is ifstream undefined?
		ifstream inputFile;
		inputFile.open(inputData);

		if (inputFile.is_open())
		{
			int rows, columns;
			inputFile >> rows;
			inputFile >> columns;


			//create a Matrix object from Matrix.h
			Matrix dataMatrix = new Matrix(rows, columns);

			//Need to define the temporary 'word' object, to store each value as it is read from inputFile.
			String word;
			//Stores all values from input file into the Matrix object
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					inputFile >> word;
					//Use a Set() function from Matrix.h to store the values
					dataMatrix.set(i, j, word);
				}
			}

			//Closing input file
			inputFile.close();

			//Successful completion, return Matrix object
			return dataMatrix;
		}
		//Error occurred - return some sort of error?
		return 0;
	}
};
#endif