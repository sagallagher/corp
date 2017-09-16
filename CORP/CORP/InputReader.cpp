/*
#include <iostream>
#include <fstream>
#include <string>
#include"stdafx.h"
using namespace std;

int main()
{
	
	Select input file
	File options:
	dodecahedron_facets.txt
	icosahedron_facets.txt
	24cell_facets.txt
	120cell_facets.txt
	600cell_facets.txt

	ifstream inputFile;
	int word;

	//Input File variable options, eventually obtain from Options parser
	string dodec = "dodecahedron_facets.txt";
	string icos = "	icosahedron_facets.txt";
	string cell24 = "24cell_facets.txt";
	string cell120 = "120cell_facets.txt";
	string cell600 = "600cell_facets.txt";

	inputFile.open(cell24);

	if (inputFile.is_open())
	{
		//Rows and columns method not feasible for higher level polytopes? ie 120cell, 600cell
		int rows, columns, product;
		inputFile >> rows;
		inputFile >> columns;
		product = rows * columns;

		//Currently, assume using 24cell inputs
		int matrix[24][6];

		cout << "Rows:\t\t" << rows << endl;
		cout << "Columns:\t" << columns << endl << endl;


		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				inputFile >> word;
				matrix[i][j] = word;
			}
		}

		//Printing the matrix isn't necessary

		//for (int i = 0; i < rows; i++)
		//{
		//	for (int j = 0; j < columns; j++)
		//	{
		//		cout << matrix[i][j] << " ";
		//		// word << "  ";
		//	}
		//	cout << endl;
		//}


		inputFile.close();
	}
	else cout << "Unable to read file.";

	return 0;
}

*/