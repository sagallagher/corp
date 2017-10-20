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

//constructor
Cover::Cover(const Star &star)
{
	Star astar(star);
	_star = astar;
	BoolSet bs(_star.numberOfVertices());
	_bitVector = bs;
}

//copy constructor
Cover::Cover(Cover & original)
{
    _star = original._star;
    _bitVector = original._bitVector;
}

//destructor
Cover::~Cover()
{
    //TODO: destructor
}

//overloaded brackets
bool & Cover::operator[](int index)
{
	return _bitVector[index];
}

//overloaded brackets
bool Cover::operator[](int index) const
{
	return _bitVector[index];
}

//selects the vertex at the given index
void Cover::select(int index)
{
	_bitVector.setTrue(index);
}

//deselects the vertex at the given index
void Cover::deselect(int index)
{
	_bitVector.setValue(index, false);
}

//checks if the given vertex list is a valid cover
bool Cover::checkCover()
{
    BoolSet tempSet(_star.numberOfFacets());
    for(int i = 0; i < _bitVector.length(); i++)
    {
        if(_bitVector[i])
        {
            for(int j = 0; j < _star._vertexMatrix.getCols(); j++)
            {
                tempSet.setTrue(_star._vertexMatrix.get(i, j));
            }
        }
    }
    return tempSet.allTrue();
}

//returns the percent of facets covered by the current vector
double Cover::coverPercent()
{
    BoolSet tempSet(_star.numberOfFacets());
    for(int i = 0; i < _bitVector.length(); i++)
    {
        if(_bitVector[i])
        {
            for(int j = 0; j < _star._vertexMatrix.getCols(); j++)
            {
                tempSet.setTrue(_star._vertexMatrix.get(i, j));
            }
        }
    }
    return (double)tempSet.numberSelected()/tempSet.length();
}

//returns the number of facets covered
int Cover::facetsCovered()
{
    BoolSet tempSet(_star.numberOfFacets());
    for(int i = 0; i < _bitVector.length(); i++)
    {
        if(_bitVector[i])
        {
            for(int j = 0; j < _star._vertexMatrix.getCols(); j++)
            {
                tempSet.setTrue(_star._vertexMatrix.get(i, j));
            }
        }
    }
    return tempSet.numberSelected();

}

//returns the total number of facets
int Cover::facets()
{
    return _star.numberOfFacets();
}

//returns the total number of vertices
int Cover::facets()
{
    return _star.numberOfVertices();
}

