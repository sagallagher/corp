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

	//calculate bounds
    calculateBounds();
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

Star::~Star()
{

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

//sets secondary matrix NOT WORKING
void Star::matrixConvert()
{
    _vertexMatrix = new Matrix<int>(_numberOfVertices, _facetsPerVertex);
    std::vector<int> indexArray(_vertexMatrix.getRows(), 0);
    int curVertex = 0;
    int curFacet = 0;
    //loop through original matrix
    for (int curRow = 0; curRow < _matrix.getRows(); curRow++)
    {
        for (int curCol = 0; curCol < _matrix.getCols(); curCol++)
        {
            //get the current vertex and facet
            curVertex = _matrix.get(curRow, curCol);
            curFacet = curRow;
            //insert that facet into the new matrix
            _vertexMatrix.set(curFacet, curVertex, indexArray[curVertex]);
            //incriment index
            indexArray[curVertex]++;
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






