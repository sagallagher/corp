/**
*  file:	Cover.h
*  author:	Sarah McGlasson
*  date:	10/1/2017
*  updated:	10/4/2017
*
*  The header file for the Cover class
*
*/

#ifndef _COVER_
#define _COVER_
#include "../Boolset/BoolSet.h";

class Cover
{
protected:
	
	BoolSet _bitVector;									//Boolset representing selected vertices
	//Star _star;										//the star object holding shape information

public:
	Cover();											//Constructor
	Cover(const Cover& original);						//copy constructor
	Cover& operator=(const Cover& original);			//overloaded equals
	~Cover();											//Destructor
	bool& operator[](int index);						//overloaded brackets
	bool operator[](int index) const;					//overloaded brackets

	void select(int index);								//selects the vertex at the given index
	void deselect(int index);							//deselects the vertex at the given index
	bool checkCover();									//checks if the given vertex list is a valid cover
	double coverPercent();								//what percent of facets are covered
	int facetsCovered();								//how many facets are covered
	int facets();										//total number of facets
	//void setStar(Star star);							//sets the star to a new star object
	void setVector(BoolSet vector);						//sets the set of vertices to the given one
	BoolSet getVector();								//returns the current _bitVector boolset											

#endif
};