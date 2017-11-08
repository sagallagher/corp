#ifndef _GENETIC_ALGORITHM_
#define _GENETIC_ALGORITHM_

#include"Crossover/GeneticOperator/Crossover.h"
#include"InitializePopulation/GeneticOperator/InitializePopulation.h"
#include"Mutation/GeneticOperator/Mutation.h"
#include"ParentSelection/GeneticOperator/ParentSelection.h"
#include"SurvivorSelection/GeneticOperator/SurvivorSelection.h"
#include"Chromosome/GeneticOperator/Chromosome.h"
#include"Genotype/GeneticOperator/Genotype.h"

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

  // store a population of chromosomes
  Genotype _genotype;

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
