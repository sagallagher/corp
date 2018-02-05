/*
*  file:	BitFlipMutation.cpp
*  author:	Steven Gallagher
*  date:	12/05/2017
*  updated:	1/30/2017
*
* get fitness based on cover percent and number of vertices selected
*
*/

#include "BitFlipMutation.h"
#include <ctime>

// flip a random bit in the bitvector of each chromosome
bool BitFlipMutation::mutateAll(Genotype& genotype) 
{
	Cover cover;
	for (Chromosome& chromo : genotype.getChromosomes())
	{

		cover = chromo.getCover();

		int rand_index = rand() % cover._bitVector.length();

		if (cover._bitVector.getValue(rand_index) == 0)
			cover.select(rand_index);

		else cover.deselect(rand_index);

		chromo.setCover(cover);
		
	}

	return true;
}

// seed random number generation and mutate chromosomes
bool BitFlipMutation::mutateGenotype(Genotype& genotype) 
{
	srand(std::time(nullptr));
	return mutateAll(genotype);
}