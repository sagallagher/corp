#include"BeamSearch.h"

BeamSearch::BeamSearch() {}

// get 2d matrix from cover
std::vector<std::vector<bool>> BeamSearch::getMatrix2D(Cover& cover)
{
  std::vector<std::vector<bool>> matrix_2d;
  int rows = cover._star->_matrix.numRows();
  int cols = cover._star->_matrix.numColumns();
  for(int i = 0; i < rows;i++)
  {
    for(int j = 0; j < cols;j++)
    {
      std::cout << i << "\t|\t" << j << std::endl;
      //std::cout << cover._star->_matrix.get(i,j) << std::endl;
    }
  }

  return matrix_2d;
}

// get the number of facets each vertice covers as a dictionary
std::map<int,int> BeamSearch::getFacetCounts(Cover& cover)
{
  std::vector<std::vector<bool>> matrix_2d = getMatrix2D(cover);

  std::map<int,int> result;

  // loop through each vertice, current_vertice i.e loop from 0-24
  for(int current = 0; current < cover._bitVector.length();current++)
  {
    // initialize map count
    result[current] = 0;

    // loop through each row of matrix 2d
    for(auto row : matrix_2d)
    {
      // loop through each column of matrix 2d
      for(auto col: row)
      {
            // if item at matrix_2d[i,j] == result[current_vertice] = result[current_vertice]++;
            if(col == current) result[current] = result[current]+1;
      }
    }
  }

  for(auto key : result)
  {
    std::cout << key.first << "\t|\t" << key.second << std::endl;
  }

}

void BeamSearch::run(Star* star)
{
  int k = 3;

  // need a cover to work with
  Cover cover(star);

  // pass cover to recursive helper method
  runHelper(cover, k);
}

// recrusive helper
void BeamSearch::runHelper(Cover& cover, int k)
{
  // do all this for each vertice
  for (int vertex = cover.vertices(); vertex >= 0; vertex--)
  {
    // if we found a solution
    if (cover.checkCover())
    {
      std::cout << "aaghh\n";
      // store it
      //_solutions.push_back(solution);

      // kill this branch because every solution following will be a solution of greater length
  		return;
    }

    // get the number of times each vertice appears in a facet in descending order
    std::map<int,int> facet_counts = getFacetCounts(cover);

    // go the width of the branching factor
    for(int i = 0; i < _k;i++)
    {
      // recurse with the next vertice we should select
      //cover.select(facet_counts.at(i));
      runHelper(cover,k);
    }
  }

}
