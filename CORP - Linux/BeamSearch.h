#include"Algorithm.h"
#include"Cover.h"
#include<map>

class BeamSearch : public Algorithm {

public:

  // constructor
  BeamSearch();

  // overwrite algorithms run
  void run(Star* star);

private:

  // get the number of facets each vertice covers
  std::map<int,int> getFacetCounts(Cover& cover);

  // recrusive helper
  void runHelper(Cover& _cover, std::vector<int>& solution, int k, int MAX_SIZE);

  // get max item and remove it
  int getAndRemoveMax(std::map<int,int>& map);

  // display map of freq counts
  void displayFacetCounts(std::map<int,int> map);


};
