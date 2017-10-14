#ifndef _INPUT_PARSER_GUARD
#define _INPUT_PARSER_GUARD
//Seth Hostetler
//Takes input stream object, stores data into a Matrix object
//-functions:
//parse()
//getMatrix()
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
		Matrix<int> getMatrix();

	protected:
		std::istream& _is;

	private:
		Matrix<int> _dataMatrix;
		void parse();
};
#endif