#ifndef _INPUTPARSER_H
#define _INPUTPARSER_H
//Seth Hostetler
//Moves data into a matrix object
//-functions
//-out of the ordinary: 
/*
	Detailed description
	parse functions does ____
*/
//analysis - How long does it take?

#include "../OptionContainer/OptionContainer.h"
#include "../Matrix/Matrix.hpp"

#include <iostream>
#include <fstream>
#include <string>


class InputParser
{
	public:

		InputParser(std::istream& in) : _is{ in };

		virtual ~InputParser();

	protected:
		std::istream& _is;

	//change back to Matrix::Matrix<int>
	Matrix<int>* parse();
};
#endif