/*
  Austin Gladfelter
  Star class uses a matrix structure

*/

#include "Star.h"

//Constructor
Star::Star(Matrix<int>* matrix)
{
	//_matrix = matrix;
	//calculate bounds
	int count = 0;
	int maxVal = 0;
	for (int i = 0; i < _matrix.getRows; i++)
	{
		for (int j = 0; j < _matrix.getCols; j++)
		{
			int val = _matrix.get(i, j);
			if (val == 1)
				count++;
			if (val > maxVal)
				maxVal = val;
		}
	}
	_upperBound = maxVal;
	_lowerBound = _matrix.getRows() / count;
	_numberOfFacets = _matrix.getRows();
	_numberOFVertices = maxVal;

}

//Copy Constructor
Star::Star(const Star& original)
{

}

//Destructor
Star::~Star()
{

}

//Returns the number of rows
int Star::rows(int& r, int& c)
{
	return _matrix.getRows();
}

//Returns the number of columns
int Star::cols(int& r, int& c)
{
	return _matrix.getCols();
}


//Valculates the theoretical minimum vertices
int Star::lowerBound()
{
	
}

//Calculates the theoretical maximum vertices
int upperBound(int& r, int& c)
{

}

//return the matrix obj
Matrix<int> & getMatrix()
{

}

int numberOfFacets()
{

}

int numberOfVertices()
{

}

int _lowerBound()
{

}

int _upperBound()
{

}

int _starRows()
{

}

int _vertex()
{

}



