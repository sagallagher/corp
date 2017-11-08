#ifndef _GENETIC_ALGORITHM_
#define _GENETIC_ALGORITHM_

#include"Crossover/Crossover.h"
#include"InitializePopulation/InitializePopulation.h"
#include"Mutation/Mutation.h"
#include"ParentSelection/ParentSelection.h"
#include"SurvivorSelection/SurvivorSelection.h"
#include"Chromosome/Chromosome.h"

class GeneticAlgorithm {

private:
  // take in 2 parents, return population
  Crossover* _crossover;

  // take in genotype, return mutated genotype
  Mutation* _mutation;

  // take in population, return parents
  ParentSelection* _parent_selection;

  // store pointer to a SurvivorSelection
  SurvivorSelection* _survivor_selection;

  // store pointer to a InitializePopulation
  InitializePopulation* _initialize_population;

  // vector of chromosomes to represent the genotype
  std::vector<Chromosome> _genotype;

public:

  // run the genetic algorithm
  bool run(Cover& cover);

  GeneticAlgorithm(Crossover& crossover,
    Mutation& mutation,
    ParentSelection& parent_selection,
    SurvivorSelection& survivor_selection,
    InitializePopulation& initialize_population);


};

#endif
