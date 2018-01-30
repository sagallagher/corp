
#include"CoverPercentRatioFitness.h"

bool CoverPercentRatioFitness::setFitness(Genotype& genotype) {

	for (Chromosome& chromo : genotype.getChromosomes()) {
		chromo.setFitness(chromo.getCover().coverPercent());
	}

	return true;
}

