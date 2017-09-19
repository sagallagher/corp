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
	std::array<T> (int, int)
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


			Matrix data = new Matrix(rows, columns);

			string word;

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{

					ary[i][j] = word;
					dataMatrix.set(i, j, word);
				}
			}
			delete[] ary;		
			return data;
		}
	data << m.toStringC)
	return OS;

};






#endif
