/**
*  file:	Cover.cpp
*  author:	Sarah McGlasson
*  date:	10/1/2017
*  updated:	10/4/2017
*
*  This class contains a boolset and takes a star object to control vertex selection
*
*/

#include "Cover.h"

//constructor
Cover::Cover()
{

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
	// TODO: insert return statement here
}

//overloaded brackets
bool Cover::operator[](int index) const
{
	return false;
}

//selects the vertex at the given index
void Cover::select(int index)
{
}

//deselects the vertex at the given index
void Cover::deselect(int index)
{
}

//checks if the given vertex list is a valid cover
bool Cover::checkCover()
{
	return false;
}

//returns the percent of facets covered by the current vector
double Cover::coverPercent()
{
	return 0.0;
}

//returns the number of facets covered
int Cover::facetsCovered()
{
	return 0;
}

//returns the total number of facets
int Cover::facets()
{
	return 0;
}

//sets the star to cover to a new star object
/*void Cover::setStar(Star star)
{
	//need star class to finish
}
*/
//sets the vertex vector to a new one
void Cover::setVector(BoolSet vector)
{

}

//returns the current list of selected vertices
BoolSet Cover::getVector()
{
	return BoolSet();
}
