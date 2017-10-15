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
Cover::Cover()
{
	//TODO: constructor, take a star as the perameter

}

//copy constructor
Cover::Cover(const Cover & original)
{
}

//overloaded equals
Cover & Cover::operator=(const Cover & original)
{
	// TODO: insert return statement here
}

//destructor
Cover::~Cover()
{

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
	//TODO: check through bitvector, make a temp boolset to represent facets, turn on, if temporary boolset is all true, it is a cover
	return false;
}

//returns the percent of facets covered by the current vector
double Cover::coverPercent()
{
	//TODO: similar to above, but divides the number covered by the number of facets
	return 0.0;
}

//returns the number of facets covered
int Cover::facetsCovered()
{
	//TODO: similar to above but returns number of facets
	return 0;
}

//returns the total number of facets
int Cover::facets()
{
	//TODO: return the number of facets from the star
	return 0;
}
