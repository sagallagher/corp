#ifndef _MUTATION_GUARD_
#define _MUTATION_GUARD_

#include"../Chromosome/Chromosome.h"
#include<vector>

class Mutation {

private:

public:

    virtual Mutation() = 0;

    // apply a mutation to the genotype
    virtual start(std::vector<Chromosome>& genotype) = 0;

};

#endif
