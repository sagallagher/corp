/*
  Austin Gladfelter
  Star class uses a matrix structure

*/

#include "Star.h"

//Constructor
Star::Star(Matrix<int>* matrix)
{
	_matrix = matrix;

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
	_facetsPerVertex = count;
	_upperBound = maxVal;
	_lowerBound = _matrix.getRows() / count;
	_numberOfFacets = _matrix.getRows();
	_numberOfVertices = maxVal;

	//calculate secondary matrix
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

//Copy Constructor
Star::Star(const Star& original)
{
	_upperBound = original.upperBound();
	_lowerBound = original.lowerBound();
	_numberOfFacets = _matrix.getRows();
	_numberOfVertices = maxVal;

}

//Destructor
Star::~Star()
{
	//TODO: DOUBLE CHECK THIS IS CORRECT
	delete _matrix;
	delete _vertexMatrix;
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
	return _lowerBound;
}

//Calculates the theoretical maximum vertices
int Star::upperBound()
{
	return _upperBound;
}

int Star::numberOfFacets()
{
	return _numberOfFacets;
}

int Star::numberOfVertices()
{
	return _numberOfVertices;
}



