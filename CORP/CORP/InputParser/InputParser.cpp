#define _CRTDBG_MAP_ALLOC
#include<iostream>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

#include "InputParser.h"
#include<sstream>

InputParser::InputParser(std::ifstream& in) : _is{ in } { parse(); }

int InputParser::getRowCount() {
	std::string str;
	int rows = 0;
	while (std::getline(_is, str)) { rows++; }
	_is.clear();
	_is.seekg(0, std::ios::beg);
	return rows;
}

int InputParser::getColumnCount() {
	std::string line;
	std::getline(_is,line);
	std::istringstream ss(line);
	int num;
	int cols = 0;
	while (ss >> num) { cols++; }
	_is.clear();
	_is.seekg(0, std::ios::beg);
	return cols;
}

//Stores all values from input file into the Matrix object
void InputParser::parse() {

	int cols = getColumnCount();
	int rows = getRowCount();
	
	_dataMatrix = Matrix<int>(rows, cols);

	int i = 0, j = 0;

	std::string str;
	
	while (std::getline(_is, str)) {
		std::istringstream ss(str);

		int num;
	
		// loop through each int in the line
		while (ss >> num) {
		
			// append that int to "row" vector; num-1 because index starts at 0
			_dataMatrix.set(num-1, i, j);
			std::cout << "set an item of data matrx " << i << "\t" << j <<  "\t" << num << std::endl;
			j++;
		}
		i++;
		j = 0;
		
	}

}

Matrix<int> InputParser::getMatrix() { return _dataMatrix; }