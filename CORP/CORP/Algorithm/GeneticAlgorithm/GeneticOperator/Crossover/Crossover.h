#ifndef _CROSSOVER_GUARD_
#define _CROSSOVER_GUARD_

#include"../GeneticOperator.h"

class Crossover : GeneticOperator {

private:

	// perform a crossover and produce offspring
	virtual bool performCrossover(Genotype&) = 0;

	// replace members in genotype with offspring
	virtual bool selectSurvivors(Genotype&) = 0;

	
};

#endif