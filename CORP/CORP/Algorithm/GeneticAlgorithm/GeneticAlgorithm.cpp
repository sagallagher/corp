#include"GeneticAlgorithm.h"

GeneticAlgorithm(Crossover& crossover,
    Mutation& mutation,
    ParentSelection& parent_selection,
    SurvivorSelection& survivor_selection,
    InitializePopulation& initialize_population)
    : _crossover { crossover},
    _mutation { mutation },
    _parent_selection { parent_selection },
    _survivor_selection { survivor_selection },
    _initialize_population { initialize_population } {}

bool GeneticAlgorithm::run() {

  // return a genotype
  _initialize_population.start();

  while(/*termination condition not met*/) {

    // take in _population
    _fitness.start();
    _crossover.start();
    _mutation.start();
    _survivor_selection.start();

  }

  return true;
}
