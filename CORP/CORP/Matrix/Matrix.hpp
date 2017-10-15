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

	Matrix(const unsigned _rows, const unsigned _cols)
	{
		m = NULL;
		allocate(_rows, _cols);
	}

	~Matrix()
	{
		deallocate();
	}

	//get elements from Matrix
	template<typename T>
	int get(const unsigned r, const unsigned c) const
	{
		return m[r][c];
	}

	//add elements to Matrix
	inline void set(const T& t, const unsigned r, const unsigned c)
	{
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

	//puts out contents of Matrix as a single string
	std::string toString()
	{

		std::string result;
		for (int i = 0; i < _rows; i++)
		{
			for (int j = 0; j < _cols; j++) {
				result.append(std::to_string(m[i][j]));

			}
		}
		return result;

	}

	friend std::ostream& operator << (std::ostream&, const Matrix<T> &_matrix)
	{
		OS << _matrix.toString();
		return OS
	}

	Matrix& operator= (Matrix& rhs) {
		m = rhs.m;
		_rows = rhs._rows;
		_cols = rhs._cols;
		return *this;

	}

private:
	//constructor
	void allocate(const unsigned _rows, const unsigned _cols)
	{
		m = new T*[_rows];
		for (int i = 0; i < _rows; i++)
		{
			m[i] = new T[_cols]
		}
	}

	//destructor
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
			delete[] m[i];
		}
		delete[] m;

		//reset
		_cols = 0;
		_rows = 0;
		m = nullptr;
	}


};

#endif
