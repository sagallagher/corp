/*
  Austin Gladfelter
  Star class uses a matrix structure

*/

#include "Star.h"

//Constructor
Star::Star()
{
	_star = new Matrix<int>();

	int _starRows = 0;
	int _starCols = 0;
}

//Copy Constructor
Star::Star(Matrix<int>* _star)
{
	
	_starRows = _star->getRows;
	_starCols = _star->getCols;
}


//Destructor
Star::~Star()
{
	delete[] _star;
}

//Returns the number of rows
int Star::getStarRows(Matrix<int>* _star)
{
	return _starRows;
}

//Returns the number of columns
int Star::getStarCols()
{
	return _starCols;
}


//Valculates the theoretical minimum vertices
int getLowerBound(Matrix<int>* _star)
{
	for each(int i in _star)
	{
		i = _vertex;

		_lowerBound = _starRows / _starCols
	}
}

//Calculates teh theoretical maximum vertices
int getUpperBound(Matrix<int>* _star)
{
	for each (i in _star)
	{

	}
}




