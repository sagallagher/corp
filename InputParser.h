#pragma once

#include "OptionContainer.h"
#include "Matrix.h"

#include <iostream>
#include <fstream>
#include <string>

//Given input file name by OptionContainer, 'input.txt' for instance.

public:
	ParseInput(string inputData)
	{
		ifstream inputFile;
		inputFile.open(inputData);

		if (inputFile.is_open())
		{			
			int rows, columns;
			inputFile >> rows;
			inputFile >> columns;

			int* ary = new int[rows][columns];

			//create a Matrix object from Matrix.h
			Matrix dataMatrix = new Matrix(rows, columns);


			//Stores all values from input file into the Matrix object
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					inputFile >> word;
					//Use a Set() function from Matrix.h to store the values
					matrix[i][j] = word;
					dataMatrix.set(i, j, word);
				}
			}
			
			//Delete the array after creating the matrix.
			delete[] ary;		//Is this correct?
			inputFile.close();

			//Successful completion, return Matrix object
			return dataMatrix;
		}
		return nullptr;
	}
