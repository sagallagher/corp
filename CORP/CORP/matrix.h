#pragma once

#include "OptionContainer.h"

template <class T>
class Matrix
{
public:
	Matrix(int rows, int cols)
	{
		setRow(rows);
		setCol(cols);

		data = new T*[rows];

		for (int i = 0; i < row; i++) {
			data[i] = new T[cols]; 
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < cols; j++) {
				data[i][j] = (T)i * j;
			}
		}
	}
	
	//needs to be implemented
	void setRow(int r) { row = r; }
	void setCol(int c) { col = c; }
	T& operator()(int row, int col);
private:
	T **data;
	int row, col;
};



template<class T> T& Matrix<T>::operator()(int row, int col)
{
	return data[row][col];
}
