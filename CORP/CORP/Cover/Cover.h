/**
*  file:	Cover.h
*  author:	Sarah McGlasson
*  date:	10/1/2017
*  updated:	10/12/2017
*
*  The header file for the Cover class
*
*/

#ifndef _COVER_GUARD_
#define _COVER_GUARD_
#include<iostream>
#include "../Boolset/BoolSet.h";
#include "../Star/Star.h";

class Cover
{
protected:
	
    

public:
    BoolSet _bitVector;							//Boolset representing selected vertices
    Star _star;                                 //the star object holding shape information
    
	Cover(Star& star);							//Constructor
	Cover(Cover& original);				//copy constructor
	~Cover();									//Destructor
	bool& operator[](int index);				//overloaded brackets
	bool operator[](int index) const;			//overloaded brackets

	void select(int index);						//selects the vertex at the given index
	void deselect(int index);					//deselects the vertex at the given index
	bool checkCover();							//checks if the given vertex list is a valid cover
	double coverPercent();						//what percent of facets are covered
	int facetsCovered();						//how many facets are covered
	int facets();								//total number of facets
    int vertices();								//total number of vertices
};

#endif