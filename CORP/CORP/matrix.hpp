#ifndef _Matrix_GAURD	
#define _Matrix_GUARD 1
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "InputParser.h"
#include "OptionContainer.h"

template <typename T>
Class Matrix 
{
	std::vector<T> inner
public:
	friend standard::stream operator << (std::ostream os, const Matrix<T> &m)

	//nested loop
	OS << m.toString
		int val = -1

		while (!infile.eof() && !infile.fail())
			//infile >> val;
		{
			int rows, columns;
			inputFile >> rows;
			inputFile >> columns;


			int* ary = new int[rows][columns];


			Matrix dataMatrix = new Matrix(rows, columns);

			string word;

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					inputFile >> word;
					//Use a Set() function from Matrix.h to store the values
					ary[i][j] = word;
					dataMatrix.set(i, j, word);
				}
			}

			//Delete the array after creating the matrix.
			delete[] ary;		


			//Successful completion, return Matrix object
			return Matrix;
		}
	word << m.toStringC)
	return OS;

};






#endif
