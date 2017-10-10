#ifndef _INPUT_PARSER
#define _INPUT_PARSER
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

	Matrix<int>* parse();
};
#endif