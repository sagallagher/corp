#define _CRTDBG_MAP_ALLOC
#include<iostream>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

#ifndef _MATRIX_GUARD_
#define _MATRIX_GUARD_
//Austin Gladfelter
//Generic, isolated matrix utility class
//contains functions: get, set, getRows, getCols, toString
//constructor and destructor located at the bottom
/*
Matrix is a dynamic 2 dimensional array.
_rows is a dynamic array of pointers.
The pointers in _rows[] point to arrays _cols
-There is only one _rows array and multiple _cols arrays
Type must be specified when calling Matrix

The set function adds one element at a time - code calling this function must have its
own loops iterating through input to add multiple values
*/
//analyis N/A

#include<string>
#include<iostream>

template <typename T> class Matrix

{
	unsigned _rows;
	unsigned _cols;
	T **m;

public:


	Matrix()
	{
		m = nullptr;
		_cols = 0;
		_rows = 0;
	}

	Matrix(unsigned _rows, unsigned _cols)
	{
		m = nullptr;
		allocate(_rows, _cols);
		// = rows;
		//_cols = cols;
	}

	~Matrix()
	{
		//delete[] m;
		//m = nullptr;
	}

	//get elements from Matrix
	int get(unsigned r, unsigned c) const
	{
		//std::cout << "Getting value " << m[r][c] << " at " << r << ", " << c <<"\n";
		return m[r][c];
	}

	//add elements to Matrix
	void set(const T& t, unsigned r, unsigned c)
	{
		//std::cout << "Setting value at " << r << ", " << c << " to " << t << "\n";
		m[r][c] = t;
	}

	//retrieve dimensions
	int getRows() const
	{
		return _rows;
	}

	int getCols() const
	{
		return _cols;
	}

	void setRows(int num) {
		_rows = num;
	}

	void setCols(int num) {
		_cols = num;
	}

	//puts out contents of Matrix as a single string
	std::string toString() {

		std::string result;
		for (int i = 0; i < _rows; i++)
		{
			for (int j = 0; j < _cols; j++) {
				result.append(std::to_string(m[i][j]));
				result.append(" ");
	
			}
			result.append("\n");
		}
		return result;

	}


	Matrix<T>& operator= ( const Matrix<T>* rhs) 
	{
		//kill prev
		//deallocate(this->m);
		//std::cout << "called overloaded =\n";
		//allocate
		allocate(rhs->_rows, rhs->_cols);
		//std::cout << "realocated\n";
		// copy (nested loops)
		if (m != nullptr)
		{ 
			_rows = rhs->getRows();
			_cols = rhs->getCols();
			//std::cout << "if statement was true\n";
			//ROWS AND COLS CORRECT AT THIS POINT!!!!!!!!
			for (int i = 0; i < _rows; i++)
			{
				//std::cout << "looped through a row\t" << i << std::endl;

				for (int j = 0; j < _cols; j++)
				{
					//std::cout << "looped through a column\t" << j << std::endl;
					m[i][j] = rhs->get(i, j);
				}
			}
		}
		//std::cout << "END OF EQUALS CHECK: \t" << _rows << " " << _cols << "\n";
		//std::cout << "skipped all that\n";
		return *this;

		

		// cant point at old matrix because it is deleted


	}

private:

	void allocate(unsigned rows, unsigned cols)
	{
		_rows = rows;
		_cols = cols;
		m = new T*[rows];
		for (int c = 0; c < rows; c++)
		{
			m[c] = new T[cols];
		}
	}


	void deallocate()
	{
		
		if (nullptr == m)
		{
			//do nothing
			return;
		}
		
		//release memory
		for (int r = 0; r < _rows; r++)
		{
			std::cout << "releasing mem\t" << r << std::endl;
			delete[] m[r];
			m[r] = nullptr;
		}
		std::cout << "delting m\n";
		delete[] m;
		std::cout << "m deleted\n";

		m = nullptr;
		std::cout << "m is now nullptr\n";
	}


};

#endif
