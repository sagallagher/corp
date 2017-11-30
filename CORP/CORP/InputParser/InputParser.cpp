#define _CRTDBG_MAP_ALLOC
#include<iostream>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

#include "InputParser.h"
#include<sstream>

InputParser::InputParser(std::ifstream& in) : _is{ in }
{}

// Stores all values from input file into the Matrix object
Matrix<int>* InputParser::parse()
{
    //
    // The first value we expect to read is the number of facets in the file
    //
    unsigned rows, columns;
    _is >> rows >> columns;

    // Allocate the matrix
    Matrix<int>* matrix = new Matrix<int>{ rows, columns };

    // Read in the the contents of the array
    unsigned tempVal;
    for (unsigned r = 0; r < rows; r++)
    {
        for (unsigned c = 0; c < columns; c++)
        {
            _is >> tempVal;
            matrix->set(r, c, tempVal);
			std::cout << "TempVal\t" << tempVal << std::endl;
            std::cout << matrix->get(r, c) << " ";
        }
        std::cout << std::endl;
    }

    _is.close();
    return matrix;
}
//
//int InputParser::getRowCount() {
//    std::string str;
//    int rows = 0;
//    while (std::getline(_is, str)) { rows++; }
//    _is.clear();
//    _is.seekg(0, std::ios::beg);
//    return rows;
//}
//
//int InputParser::getColumnCount() {
//    std::string line;
//    std::getline(_is, line);
//    std::istringstream ss(line);
//    int num;
//    int cols = 0;
//    while (ss >> num) { cols++; }
//    _is.clear();
//    _is.seekg(0, std::ios::beg);
//    return cols;
//}