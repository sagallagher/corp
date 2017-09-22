//
//  Matrix.cpp
//  main checks to see what the inputFile is, then uses a corresponding class inheriting from Matrix
//  setMatrix is called and creates a list of arrays based on column size and creates rows(arrays) of size _columns
//  Created by Austin Gladfelter.
// 
#include "Matrix.hpp"
#include <fstream>
int main() {
    
    //120cell
    if (fstream = "120cell_facets.txt"){
        Matrix = _cell20.setMatrix();
    } else{
        return 0;
    }
    return Matrix;
    
    
    //24cell
    if (fstream = "24cell_facets.txt"){
        Matrix = _cell24.setMatrix();
    } else{
        return 0;
    }
    return Matrix;
    
    
    //600 cell
    if (fstream = "600cell_facets.txt"){
        Matrix = _cell600.setMatrix();
    } else{
        return 0;
    }
    return Matrix;
    
    //dodecahedron
    if (fstream = "dodecahedron_facets.txt"){
        Matrix = _dodecahedron.setMatrix();
    } else{
        return 0;
    }
    return Matrix;
    
    
    //icosehredon
    if (fstream = "icosehedron_facets.txt"){
        Matrix = _icosehredon.setMatrix();
    } else{
        return 0;
    }
    return Matrix;
};
