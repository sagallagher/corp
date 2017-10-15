#ifndef _INPUT_PARSER_GUARD
#define _INPUT_PARSER_GUARD
//Seth Hostetler
//Takes input stream object, stores data into a Matrix object
//Contains functions parse, getMatrix
/*
	InputParser is a class that takes an input stream object
		and stores the data in a Matrix object.
	_is is the input stream object.
	_dataMatrix is the Matrix object to store the data
	the parse function loops through the input file and
		passes the data to the Matrix Object.
*/
//analysis - How long does it take?

#include "../OptionContainer/OptionContainer.h"
#include "../Matrix/Matrix.hpp"
#include <iostream>
#include <fstream>
#include <string>

class InputParser
{
	protected:
		std::istream& _is;

	public:
		InputParser(std::istream& in);
		virtual ~InputParser();
		Matrix<int> getMatrix();
		int getRowCount();
		int getColumnCount();

	private:
		Matrix<int> _dataMatrix;
		void parse();
};
#endif