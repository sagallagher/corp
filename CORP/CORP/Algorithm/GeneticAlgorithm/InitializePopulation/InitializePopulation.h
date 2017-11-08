#ifndef _INITIALIZE_POPULATION_
#define _INITIALIZE_POPULATION_

#include"../Chromosome/Chromosome.h"
#include<vector>

class InitializePopulation {

private:
  std::vector<Chromosome>* _genotype;

public:

  virtual InitializePopulation() = 0;

  // fill genotype with population
  virtual bool start(std::vector<Chromosome>& genotype) = 0;

};

#endif
