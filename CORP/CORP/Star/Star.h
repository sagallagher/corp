#ifndef _STAR_GUARD_
#define  _STAR_GUARD_
#include "../Matrix/Matrix.hpp"
#include <iostream>

class Star
{
protected:
	Matrix<int> _matrix;
	int _numberOfFacets;
	int _numberOFVertices;
	int _lowerBound;
	int _upperBound;
	int _starRows;
	int _starCols;
	int _vertex;
public:
	//Constructor
	Star(Matrix<int>* matrix);

	//Copy Constructor
	Star();

	//Destructor
	~Star();

	//Returns the number of rows
	int rows( int& r, int& c); 

	//Returns the number of columns
	int cols( int& r, int& c);


	//Valculates the theoretical minimum vertices
	int lowerBound();

	//Calculates the theoretical maximum vertices
	int upperBound();

	//return the matrix obj
	Matrix<int> & getMatrix();

	int numberOfFacets();

	int numberOfVertices();
	
	int _starRows();

	int _vertex();
};


/*
Lower and upper bounds
find lower and upper bounds in constructor
passed in a matrix in constructor parameter

*/


#endif