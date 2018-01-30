#include "BitFlipMutation.h"
#include<ctime>

bool BitFlipMutation::mutateAll(Genotype& genotype) {
	Cover cover;
	for (Chromosome& chromo : genotype.getChromosomes()) {

		cover = chromo.getCover();



		int rand_index = rand() % cover._bitVector.length();

		if (cover._bitVector.getValue(rand_index) == 0)
			cover.select(rand_index);

		else cover.deselect(rand_index);

		chromo.setCover(cover);
		
	}

	return true;
}


bool BitFlipMutation::mutateGenotype(Genotype& genotype) {
	srand(std::time(nullptr));
	return mutateAll(genotype);
}