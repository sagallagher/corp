#include"BeamSearch.h"
#include<algorithm>

BeamSearch::BeamSearch() {}


// display map of freq counts
void BeamSearch::displayFacetCounts(std::map<int,int> map)
{
  // display counts
  for(auto key : map)
    std::cout << key.first << "\t|\t" << key.second << std::endl;
}

// get the number of facets each vertice covers as a dictionary
std::map<int,int> BeamSearch::getFacetCounts(Cover& cover)
{

  int rows = cover._star->_matrix.numRows();
  int cols = cover._star->_matrix.numColumns();


  std::map<int,int> result;

  // loop through each vertice, current_vertice i.e loop from 0-24
  for(int current = 1; current < cover._bitVector.length();current++)
  {
    // initialize map count
    result[current] = 0;

    // loop through each row of matrix 2d
    for(int i = 0; i < rows;i++)
    {
      // loop through each column of matrix 2d
      for(int j = 0;j < cols;j++)
      {
            // if item at matrix_2d[i,j] == result[current_vertice] = result[current_vertice]++;
            if(cover._star->_matrix.get(i,j) == current)
            {
              // increment the current vertices count
              result[current] = result[current]+1;

              // remove the current row from the covers matrix
              cover._star->_matrix.deleteRow(current-1);

            }
      }
    }
  }

  return result;
}

int BeamSearch::getAndRemoveMax(std::map<int,int>& map)
{
  int max_value = 0;
  int max_key = 0;

  for(auto pair : map)
  {
    if(pair.second > max_value) max_key = pair.first;
  }

  map.erase(map.find(max_key));

  return max_key;
}

void BeamSearch::run(Star* star)
{
  int k = 1;
  int MAX_SIZE = 5;

  std::vector<int> solution = {};

  // need a cover to work with
  Cover cover(star);

  // pass cover to recursive helper method
  runHelper(cover, solution, k, MAX_SIZE);
}

///////////////////////////////////////////////////////////////
// return true if an element is a vector
template<typename T>
bool inSolution(const std::vector<T>& solution, const T& element)
{
	return std::find(solution.begin(), solution.end(), element) != solution.end();
}

void displaySolution(std::vector<int> solution)
{
  for(auto item : solution)
  {
    std::cout << item << " ";
  }
  std::cout << std::endl;
}
///////////////////////////////////////////////////////////////


// recrusive helper
void BeamSearch::runHelper(Cover& cover, std::vector<int>& solution, int k, int MAX_SIZE)
{



  // do all this for each vertice
  for (int vertex = 0; vertex <= cover.vertices(); vertex++)
  {

    // if the solution is beyond on the upper bound, kill the branch
    if (solution.size() > MAX_SIZE) return;

    // if we found a solution
    if (cover.checkCover())
    {
      // store it
      _solutions.push_back(solution);
      std::cout << "SOLUTION FOUND\n";
      displaySolution(solution);
      // kill this branch because every solution following will be a solution of greater length
  		return;
    }

    // get the number of times each vertice appears in a facet
    std::map<int,int> facet_counts = getFacetCounts(cover);

    displayFacetCounts(facet_counts);

    Cover temp_cover = cover;

    std::vector<int> temp_solution = solution;

    // go the width of the branching factor
    for(int i = 0; i < k;i++)
    {

      // display solution
      displaySolution(solution);

      // get the next best of the facet counts
      int best = getAndRemoveMax(facet_counts);
      while(inSolution(temp_solution,best))
        best = getAndRemoveMax(facet_counts);

      // store in the solution
      temp_solution.push_back(best);

      // select best vert in current cover
      temp_cover.select(best);

      // recurse with new cover and solution
      runHelper(temp_cover, temp_solution, k, MAX_SIZE);
    }

  }

}
