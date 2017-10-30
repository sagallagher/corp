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

	Matrix(const unsigned rows, const unsigned cols)
	{
		m = nullptr;
		allocate(rows, cols);
		// = rows;
		//_cols = cols;
	}

	~Matrix()
	{
		//deallocate();

	}

	//get elements from Matrix
	int get(const unsigned r, const unsigned c) const
	{
		//std::cout << "Getting value " << m[r][c] << " at " << r << ", " << c <<"\n";
		return m[r][c];
	}

	//add elements to Matrix
	void set(const T& t, const unsigned r, const unsigned c)
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

	/*
	friend std::ostream& operator << (std::ostream&  OS, const Matrix<T> &_matrix)
	{
		OS << _matrix.toString();
		return OS;
	}
	*/

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
	//allocates space in the matrix
	void allocate(const unsigned rows, const unsigned cols)
	{
		_rows = rows;
		_cols = cols;
		m = new T*[rows];
		for (int i = 0; i < rows; i++)
		{
			m[i] = new T[cols];
		}
	}

	void allocate(Matrix<T>* lhs, const unsigned rows, const unsigned cols)
	{
		lhs.m = new T*[rows];
		for (int i = 0; i < rows; i++)
		{
			lhs[i] = new T[cols];
		}
	}

	//deallocates space in the matrix
	void deallocate()
	{
		
		if (nullptr == m)
		{
			//do nothing
			return;
		}
		
		//release memory
		for (int i = 0; i < _rows; i++)
		{
			std::cout << "releasing mem\t" << i << std::endl;
			delete[] m[i];
			m[i] = nullptr;
		}
		std::cout << "delting m\n";
		delete[] m;
		std::cout << "m deleted\n";

		m = nullptr;
		std::cout << "m is now nullptr\n";
	}


};

#endif
