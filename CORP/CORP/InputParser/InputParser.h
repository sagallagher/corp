#ifndef _INPUT_PARSER
#define _INPUT_PARSER


//Should InputParser contain OptionContainer.h, or is it instead called in OptionContainer ? 
#include "OptionContainer.h"
#include "Matrix.h"

#include <iostream>
#include <fstream>
#include <string>

//Given input file name by OptionContainer, 'input.txt' for instance.

class InputParser
{
	public:

		InputParser(std::istream& in) : _is{ in }
		{
		}

		virtual ~InputParser();


	protected:
		std::istream& _is;


		//In main
		ifstream _is;
		_is.open(inputData);

if (!_is)
{
	std::cerr << "Unable to open file " << name << "for reading.";
	return 1;
}
// In main



Matrix* parse();
};
#endif