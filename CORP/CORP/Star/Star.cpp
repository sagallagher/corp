/*
  Austin Gladfelter
  Star class uses a matrix structure

*/



#include "Star.h"
Star::Star() {}
//Constructor
Star::Star(Matrix<int>* matrix)
{
	_matrix = matrix;

	//calculate bounds
    calculateBounds();
    
	//calculate secondary matrix
    matrixConvert();


}

//Copy Constructor
Star::Star(Star& original)
{
	_upperBound = original.upperBound();
	_lowerBound = original.lowerBound();
	_numberOfFacets = _matrix.getRows();
	_numberOfVertices = _matrix.getCols();

}

//Destructor
/*
Star::~Star()
{
	//TODO: DOUBLE CHECK THIS IS CORRECT
	delete _matrix;
	delete _vertexMatrix;
}
*/

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
	return _lowerBound;
}

//Calculates the theoretical maximum vertices
int Star::upperBound()
{
	return _upperBound;
}

//return the number of facets
int Star::numberOfFacets()
{
	return _numberOfFacets;
}

//return the number of vertices
int Star::numberOfVertices()
{
	return _numberOfVertices;
}

//return the number of facets converging at each vertex
int Star::facetsPerVertex()
{
    return _facetsPerVertex;
}

/*
//old function to set secondary matrix **INEFICIENT**
void ineficientMatrixConvert()
{
    _vertexMatrix = new Matrix<int>(_numberOfFacets, _facetsPerVertex);
    
    for (int i = 0; i < _vertexMatrix.getRows(); i++)
    {
        int index = 0;
        for (int j = 0; j < _matrix.getRows(); j++)
        {
            for (int k = 0; k < _matrix.getCols(); k++)
            {
                if (_matrix.get(j, k) == i)
                {
                    _vertexMatrix.set(j, i, index);
                    index++;
                }
            }
        }
    }
}
*/

/*
//sets secondary matrix
void matrixConvert()
{
    _vertexMatrix = new Matrix<int>(_numberOfFacets, _facetsPerVertex);
    int indexArray[_vertexMatrix.getRows()];
    
    for (int i = 0; i < _matrix.getRows(); i++)
    {
        for (int j = 0; j < _matrix.getCols(); j++)
        {
            //loops through the list of vertices, for each one, puts the index number(facet number) in the new matrix
            _vertexMatrix[_matrix[i][j]][indexArray[i]] = i;
            indexArray[i]++;
        }
    }
}
*/


//calculates and sets bounds
void Star::calculateBounds()
{
    int count = 0;
    int maxVal = 0;
    for (int i = 0; i < _matrix.getRows(); i++)
    {
        for (int j = 0; j < _matrix.getCols(); j++)
        {
            int val = _matrix.get(i, j);
            if (val == 1)
                count++;
            if (val > maxVal)
                maxVal = val;
        }
    }
    _facetsPerVertex = count;
    _upperBound = maxVal;
    _lowerBound = _matrix.getRows() / count;
    _numberOfFacets = _matrix.getRows();
    _numberOfVertices = maxVal;

}
*





