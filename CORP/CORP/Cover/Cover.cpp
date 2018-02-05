#define _CRTDBG_MAP_ALLOC
#include<iostream>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

/**
*  file:	Cover.cpp
*  author:	Sarah McGlasson
*  date:	10/1/2017
*  updated:	10/12/2017
*
*  This class contains a boolset and takes a star object to control vertex selection
*
*/

#include "Cover.h"


Cover::Cover() {}
//constructor
Cover::Cover(Star* star) :
    _bitVector(star->numberOfVertices()),
    _facetVector(star->numberOfFacets()),
    _star { star }
{}

//copy constructor
Cover::Cover(const Cover& original) :
    _star{ original._star },
    _bitVector{ original._bitVector },
    _facetVector { original._facetVector}
{}


//destructor
Cover::~Cover()
{
}

const Cover& Cover::operator=(const Cover& original)
{
	_star = original._star;

	_bitVector = original._bitVector;

	_facetVector = original._facetVector;

	return *this;
}

//selects the vertex at the given index
void Cover::select(int index)
{
	_bitVector.setTrue(index);
	for (int i = 0; i < _star->rows(); i++)
	{
		for (int j = 0; j < _star->cols(); j++)
		{
			if (_star->_matrix.get(i, j) == index)
			{
				_facetVector.setTrue(i);
			}
		}
	}
}

//selects the vertex at the given index
void Cover::selectUnchecked(int index)
{
	std::cout << "selected index\t" << index << std::endl;
	_bitVector.setTrueUnchecked(index);

	for (int i = 0; i < _star->rows(); i++)
	{
		for (int j = 0; j < _star->cols(); j++)
		{
			if (_star->_matrix.get(i, j) == index)
			{
				_facetVector.setTrue(i);
			}
		}
	}
}

//deselects the vertex at the given index
void Cover::deselect(int index)
{
	_bitVector.setValue(index, false);
	for (int i = 0; i < _star->rows(); i++)
	{
		for (int j = 0; j < _star->cols(); j++)
		{
			if (_star->_matrix.get(i, j) == index)
			{
				_facetVector.setValue(index, false);
			}
		}
	}
	//TODO: remove facets from _facetVector
}

//checks if the given vertex list is a valid cover NOT WORKING: USES SECONDARY MATRIX
/*
bool Cover::checkCover()
{	
    BoolSet tempSet(_star->numberOfFacets());
    for(int i = 0; i < _bitVector.length(); i++)
    {
        if(_bitVector[i])
        {
            for(int j = 0; j < _star->_vertexMatrix.numColumns(); j++)
            {
                tempSet.setTrue(_star->_vertexMatrix.get(i, j));
            }
        }
    }
    return tempSet.allTrue();
}
*/

//checks if the given vertex list is a valid cover
bool Cover::checkCover() const
{
	return _facetVector.allTrue();
}


//returns the percent of facets covered by the current vector NOT WORKING: USES SECONDARY MATRIX
/*
double Cover::coverPercent()
{
    BoolSet tempSet(_star->numberOfFacets());
    for(int i = 0; i < _bitVector.length(); i++)
    {
        if(_bitVector[i])
        {
            for(int j = 0; j < _star->_vertexMatrix.numColumns(); j++)
            {
                tempSet.setTrue(_star->_vertexMatrix.get(i, j));
            }
        }
    }
    return (double)tempSet.numberSelected()/tempSet.length();
}
*/

//returns the percent of facets covered by the current vector
double Cover::coverPercent() const
{
	return (double)_facetVector.numberSelected() / _facetVector.length();
}

//returns the number of facets covered NOT WORKING: USES SECONDARY MATRIX
/*
int Cover::facetsCovered()
{
    BoolSet tempSet(_star->numberOfFacets());
    for(int i = 0; i < _bitVector.length(); i++)
    {
        if(_bitVector[i])
        {
            for(int j = 0; j < _star->_vertexMatrix.numColumns(); j++)
            {
                tempSet.setTrue(_star->_vertexMatrix.get(i, j));
            }
        }
    }
    return tempSet.numberSelected();

}
*/

//returns the number of facets covered
int Cover::facetsCovered() const
{
	return _facetVector.numberSelected();
}

//returns the total number of facets
int Cover::facets() const
{
    return _star->numberOfFacets();
}

//returns the total number of vertices
int Cover::vertices() const
{
    return _star->numberOfVertices();
}

std::string Cover::coverToString() const
{
	return " ";
}

std::string Cover::toString() const
{
	return _bitVector.toString();
}
