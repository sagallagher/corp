#ifndef _MUTATION_GUARD_
#define _MUTATION_GUARD_

#include "../GeneticOperator.h"
class Mutation {


private:
	virtual bool mutateGenotype(Genotype&) = 0;

};

#endif
