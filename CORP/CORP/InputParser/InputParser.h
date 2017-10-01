#ifndef _INPUT_PARSER
#define _INPUT_PARSER


//Updated file locations 
#include "../OptionContainer/OptionContainer.h"
#include "../Matrix/Matrix.hpp"


//#include <iostream>
//#include <fstream>
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



Matrix* parse();
};
#endif