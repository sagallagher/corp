#ifndef _FITNESS_GUARD_
#define _FITNESS_GUARD_

#include"../../Genotype/Genotype.h"

class Fitness {

public:

	// set the fitness of each chromosome in 
	virtual bool setFitness(Genotype&) = 0;

};

#endif
