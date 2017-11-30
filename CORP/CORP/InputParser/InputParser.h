#ifndef _INPUT_PARSER_GUARD
#define _INPUT_PARSER_GUARD

#define _CRTDBG_MAP_ALLOC
#include<iostream>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

#include "../OptionContainer/OptionContainer.h"
#include "../Matrix/Matrix.hpp"
#include <iostream>
#include <fstream>
#include <string>

class InputParser
{
	protected:
		std::ifstream& _is;

	public:
		InputParser(std::ifstream& in);
        Matrix<int>* parse();

	private:
};
#endif