#ifndef _MATRIX_GAURD
#define _MATRIX_GAURD

template<typename T> class Matrix
{
public:

	//member functions
	void Matrix<T>::createMatrix(unsigned rows, unsigned cols);
	void remove(unsigned row, unsigned col);
	void insert(unsigned row, unsigned col, const T &entry);
	T& item(unsigned row, unsigned col);
private:
	unsigned _rows;
	unsigned _cols;
	T** _matrix[][_cols];
};

//function definitions
{
	template<typename T>
	void Matrix<T>::createMatrix(rows, cols)
	{
		// new_matrix is an array of rows, where each row is an array of T
		unsigned new_matrix = 0;
		if (_rows && _cols)
		{
			new_matrix = new T*[_rows];
			for (unsigned row = 0; row < _rows; row++)
			{
				new_matrix[row] = new T[_cols];
				// copy old items to the _matrix 
				// fill the rest of the grid with the initial value
				for (unsigned col = 0; col < _cols; col++)
				{
					if (row < m_rows && col < _cols)
						new_matrix[row][col] = _matrix[row][col];
				}
			}
		}
		else
		{

			// destroy the old matrix
			for (unsigned row = 0; row < _rows; row++)
			{
				delete[] new_matrix[row];
				delete[] _matrix;

				// move the new entries into the new matrix
				_matrix = new_matrix;
				_rows = rows;
				_cols = cols;
			}
		}
	}

	template<typename T>
	void matrix<T>::insert(unsigned row, unsigned col, const T& entry)
	{
		_matrix[row][col] = entry;
	}

	template<typename T>
	void matrix<T>::remove(unsigned row, unsigned col)
	{
		insert(row, col);
	}

	template<typename T>
	const T& matrix<T>::item(unsigned row, unsigned col) const
	{
		return new_matrix[row][col];
	}
}

#endif // !_MATRIX_GAURD
