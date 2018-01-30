/**
*  file:	GeneticAlgorithm.h
*  author:	Steven Gallagher
*  date:	12/05/2017
*  updated:	12/05/2017
*
*  Execute a genetic algorithm with the provided
*  genetic operators.
*
*
*/



#ifndef _GENETIC_ALGORITHM_
#define _GENETIC_ALGORITHM_

#include"GeneticOperator\GeneticOperator.h"
#include"GeneticOperator\Crossover\Crossover.h"
#include"GeneticOperator\InitGenotype\InitGenotype.h"
#include"GeneticOperator\Mutation\Mutation.h"
#include"../Algorithm.h"

class GeneticAlgorithm : public Algorithm {



public:

  // run the genetic algorithm
  void run(Star* star);


};

#endif
