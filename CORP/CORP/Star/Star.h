#ifndef _STAR_GUARD_
#define  _STAR_GUARD_
#include "../Matrix/Matrix.hpp"
#include <iostream>

class Star
{
protected:

	int _numberOfFacets;
	int _numberOfVertices;
	int _lowerBound;
	int _upperBound;
	int _starRows;
	int _starCols;
	int _vertex;
	int _facetsPerVertex;

public:
		
	Matrix<int> _matrix;
	Matrix<int> _vertexMatrix;
		
	//Constructor
	Star(Matrix<int>* matrix);
	Star();
	//Copy Constructor
	Star(Star& original);

	//Destructor
	//~Star();

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

    //returns the number of facets
	int numberOfFacets();

    //returns the number of vertices
	int numberOfVertices();

    //returns the number of facets converging at each vertex
	int facetsPerVertex();
    
    //uses nested for loops to create the secondary matrix **POTENTIALLY INEFICIENT**
    void ineficientMatrixConvert();
    
    //new function to create the secondary matrix
    void matrixConvert();
    
    //caulculates and sets the bounds
    void calculateBounds();

};


#endif