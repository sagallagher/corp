#include"Algorithm.h"
#include"Cover.h"
#include<map>

class BeamSearch : public Algorithm {

public:

  // constructor
  BeamSearch();

  void run(Star* star);

private:
  // branching factor
  int _k;

  // get the number of facets each vertice covers
  std::map<int,int> getFacetCounts(Cover& cover);

  // recrusive helper
  void runHelper(Cover& _cover, int k);

  // get 2d matrix from cover
  std::vector<std::vector<bool>> getMatrix2D(Cover& cover);

};
