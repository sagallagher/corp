#ifndef _FITNESS_GUARD_
#define _FITNESS_GUARD_

#include"../Chromosome/Chromosome.h"
#include<vector>

class Fitness {

private:

public:

  virtual Fitness() = 0;

  // set the fitness of each chromosome
  virtual start(std::vector<Chromosome>& genotype) = 0;

};

#endif