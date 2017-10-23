/*
  Austin Gladfelter
  Star class uses a matrix structure

*/



#include "Star.h"
#include<vector>
Star::Star() {}
//Constructor
Star::Star(Matrix<int>* matrix)
{
	std::cout << "this print og matrix\n";
	std::cout << matrix->toString();
	_matrix = matrix;

	//std::cout << "PRE CALCULATION TEST: \t" << _matrix.getRows() << " " << _matrix.getCols() << "\n";



	//calculate bounds
    calculateBounds();
    
	//std::cout << "POST CALCULATION TEST: \t" << _matrix.getRows() << " " << _matrix.getCols() << "\n";
	//calculate secondary matrix
	//std::cout << "GETTING TEST VALUES: " << _matrix.get(0, 0) << " from 0,0 " << _matrix.get(8, 5) << " from 8,5 \n";
    matrixConvert();
	
	//std::cout << "this should be print a matrix\t";
	//std::cout << _matrix.toString();

	//ROWS AND COLS CORRECT AT THIS POINT
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

Star::~Star()
{
	//TODO: DOUBLE CHECK THIS IS CORRECT
	//delete _matrix;
	//delete _vertexMatrix;
}


//Returns the number of rows
int Star::rows()
{
	return _matrix.getRows();
}

//Returns the number of columns
int Star::cols()
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


//sets secondary matrix
void Star::matrixConvert()
{
	//std::cout << "INSIDE MATRIX CONVERT, SAMPLE VALUES:" << _matrix.get(0, 0) << " from 0,0 " << _matrix.get(8, 5) << " from 8,5 \n";
    _vertexMatrix = new Matrix<int>(_numberOfFacets, _facetsPerVertex);
    std::vector<int> indexArray(_vertexMatrix.getRows(), 0);
	//std::cout << "CONVERTING MATRIX...";
    for (int i = 0; i < _matrix.getRows(); i++)
    {
        for (int j = 0; j < _matrix.getCols(); j++)
        {

            //loops through the list of vertices, for each one, puts the index number(facet number) in the new matrix
			//Print out indexMatrixtestString << "\n";
			//for (auto it = indexArray.begin(); it != indexArray.end(); it++) std::cout << *it;
			//std::cout << std::endl;
			_vertexMatrix.set(i, _matrix.get(i, j), indexArray.at(i));
            indexArray[i]++;
        }
    }
	std::cout << "THIS IS THE OLD FACET MATRIX!\n";
	std::cout << _matrix.toString() << "\n";
	std::cout << "THIS IS THE NEW VERTEX MATRIX!\n";
	std::cout << _vertexMatrix.toString() << "\n";
}



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
    _upperBound = maxVal + 1;
    _lowerBound = _matrix.getRows() / count;
    _numberOfFacets = _matrix.getRows();
    _numberOfVertices = maxVal + 1;
}






