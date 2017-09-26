#ifndef _MATRIX_GAURD_
#define _MATRIX_GAURD_
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

namespace std
{

	template <typename T> class Matrix
		
	{
		unsigned _rows;
		unsigned _cols;
		T **_matrix;
		
	public:
		
		
		Matrix()
		{
			_matrix = NULL;
			_cols = 0;
			_rows = 0;
		}

		Matrix(const int& _rows, const int& _cols)
		{
			_matrix = NULL;
			allocate(_rows, _cols);
		}

		~Matrix()
		{
			deallocate();
		}

		//get elements from Matrix
		T get(const int& r, const int c) const
		{
			return _matrix[r][c];
		}

		//add elements to Matrix
		void set(const T& t, const int& r, const int c)
		{
			_matrix[r][c] = t;
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
		void toString()
		{
			friend std::ostream& operator << (std::ostream&, const Matrix<T> &_matrix)
			{
				OS << _matrix.toString();
				return OS
			}
		}

	private:
		//constructor
		void allocate(const int& _rows, const int& _cols)
		{
			_matrix = new T*[_rows];
			for (int i = 0; i < _rows; i++)
			{
				_matrix[i] = new T[_cols]
			}
		}

		//destructor
		void deallocate()
		{
			if (NULL == _matrix)
			{
				//do nothing
				return;
			}

			//release memory
			for (int i = 0; i < _rows; i++)
			{
				delete[] _matrix[i]
			}
			delete[] _matrix;

			//reset
			_cols = 0;
			_rows = 0;
			_matrix = NULL;
		}


	};



}



#endif 
