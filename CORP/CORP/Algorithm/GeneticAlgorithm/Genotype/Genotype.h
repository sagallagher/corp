/**
*  file:	Genotype.h
*  author:	Steven Gallagher
*  date:	12/05/2017
*  updated:	12/05/2017
*
*  Genotype is a container for chromosomes.
*/

#ifndef _GENOTYPE_GUARD_
#define  _GENOTYPE_GUARD_


#include"../../../Cover/Cover.h"
#include"Chromosome\Chromsome.h"


class Genotype {

private:
	// contains the chromosomes of the genotype
	std::vector<Chromosome> _chromosomes;


public:
	// return the genotype as a vector of chromosomes
	std::vector<Chromosome>& getChromosomes();

	// add a new chromosome to the genotype
	bool appendChromosome(Chromosome &chromosome);

	// string representation of genotype
	std::string toString();


};

#endif
