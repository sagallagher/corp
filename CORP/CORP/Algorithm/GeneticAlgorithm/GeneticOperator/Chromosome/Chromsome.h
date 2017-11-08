#ifndef _CHROMOSOME_GUARD_
#define  _CHROMOSOME_GUARD_

#include"../../../Cover/Cover.h"
#include<vector>

class Chromosome {

private:
  // store the cover for the chromosome
  Cover _cover;
  
  // store the fitness of the chromosome
  int _fitness;

public:
  // return the cover
  Cover getCover();

  // return the fitness of the chromosome
  int getFitness();



};

#endif
