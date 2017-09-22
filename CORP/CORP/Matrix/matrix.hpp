//
//  Matrix.hpp
//  matrix - called by InputParser and puts files into a matrix with _rows and
//  _columns
//  Matrix is created by using a dynamic 2D array of pointers of arrays
//  Created by Austin Gladfelter.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>
#include <fstream>

template <typename T>
class Matrix {
    
protected:
    //_columns determins array size
    int _columns;
    T *matrix;
 
    
public:
    // constructor with user pre-defined size(in columns)
    array (int c) {
        _columns = c;
        matrix = new T [_columns];
    }
    
    
    //sets values into arrays based on number of columns
    //iterates through inputFile and creates a new array of size _columns until the end of file
    //Matrix is a list of arrays
    void setMatrix (int c, T val){
        matrix[c] = val;
        if(inputFile.is_open() && !inputFile.eof)
        {
            string matrix[c];
            
            for(int i = 0; i < c; ++i)
            {
                inputFile >> matrix[i];
                
                while (!inputFile.eof)
                    _row = new T[c]
            }
        } else {return 0;}
	    
	return Matrix;
    }
    

    void getMatrix() const {
        
        
    }
    
    
    int size() const{
        return _columns.size();
    }
    
    
};


//120 cell matrix
class _cell120 : public Matrix{
    c = 20;
    setMatrix(c);
}

//24 cell matrix
class _cell24 : public Matrix{
    c = 6;
    setMatrix(c);
}

//600 cell matrix
class _cell600 : public Matrix{
    c = 4;
    setMatrix(c)
    
}

//dedecahedron matrix
class _dodechedron : public Matrix{
    c = 5;
    setMatrix(c)
}

//icosehedron facets matrix
class _icosehedron : public Matrix{
    c = 3;
    setMatrix(c)
}


#endif /* Matrix_hpp */






////  while (!inputFile.eof && !inputFile.fail){

/*
 int** ary = new int*[rowCount];
 for(int i = 0; i < rowCount; ++i)
 ary[i] = new int[colCount];
 */
