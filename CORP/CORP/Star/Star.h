#ifndef _STAR_GUARD_
#define  _STAR_GUARD_
#include "../Matrix/Matrix.hpp"
#include <iostream>

class Star
{
//protected:
	Matrix<int>* _star;
	int _numberOfFacets = 0;
	int _numberOFVertices = 0;
	int _lowerBound = 0;
	int _upperBound = 0;
	int _starRows;
	int _starCols;
	int _vertex;
public:
	//Constructor
	Star(Matrix<int>* _star);

	//Copy Constructor
	Star();

	//Destructor
	~Star();

	//Returns the number of rows
	int getStarRows(); 

	//Returns the number of columns
	int getStarCols();


	//Valculates the theoretical minimum vertices
	int getLowerBound();

	//Calculates the theoretical maximum vertices
	int getUpperBound();
};


/*
Lower and upper bounds
find lower and upper bounds in constructor
passed in a matrix in constructor parameter

*/


#endif