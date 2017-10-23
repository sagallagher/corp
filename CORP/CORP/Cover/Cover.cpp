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
Cover::Cover(Star &star)
{
	//std::cout << "ROWS AND COLS 1:\t" << star.rows() << " " << star.cols() << std::endl;
	Star astar(star);
	_star = star;
	//std::cout << "ROWS AND COLS 2:\t" << _star.rows() << " " << _star.cols() << std::endl;
	BoolSet bs(_star.numberOfVertices());
	_bitVector = bs;
	_bitVector.clear();
	//TODO:output verifiers
	//std::cout <<"ROWS AND COLS final:\t" << _star.rows() << " " << _star.cols() << std::endl;
	std::cout << "Cover Created: " << toString() << "\n";
}

//copy constructor
Cover::Cover(Cover & original)
{
	// need an overlaoded equals for star
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
	std::cout << "selected index\t" << index << std::endl;
	_bitVector.setTrue(index);
}

//selects the vertex at the given index
void Cover::selectUnchecked(int index)
{
	std::cout << "selected index\t" << index << std::endl;
	_bitVector.setTrueUnchecked(index);
}

//deselects the vertex at the given index
void Cover::deselect(int index)
{
	_bitVector.setValue(index, false);
}

//checks if the given vertex list is a valid cover
bool Cover::checkCover()
{	
	//std::cout << "calling numberOfFacets, first line of checkCover\n";
    BoolSet tempSet(_star.numberOfFacets());
    for(int i = 0; i < _bitVector.length(); i++)
    {
		//std::cout << "started the firest floor loop, length was successfull and so was numberOfFacets\n";
        if(_bitVector[i])
        {
            for(int j = 0; j < _star._vertexMatrix.getCols(); j++)
            {
                tempSet.setTrue(_star._vertexMatrix.get(i, j));
            }
        }
		//std::cout << "finished a loop of checkCover\n";
;    }
	std::cout << "finished all loops in checkCover, about to return something\n";
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
int Cover::vertices()
{
    return _star.numberOfVertices();
}

std::string Cover::coverToString()
{
	return " ";
}

std::string Cover::toString()
{
	/*
	std::string result;
	result = " ";

	for (int i = 0; i < _bitVector.length(); i++)
	{
		if (_bitVector.getValue(i))
			result.append("1");
		else
			result.append("0");
	}
	*/
	return _bitVector.toString();
}

