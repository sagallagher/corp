#include"GeneticAlgorithm.h"
#include"GeneticOperator\InitGenotype\RandomInitGenotype\RandomInitGenotype.h"
#include"Genotype\Genotype.h"




#include"GeneticOperator\Mutation\BitFlipMutation\BitFlipMutation.h"
#include"GeneticOperator\Fitness\CoverPercentRatioFitness\CoverPercentRatioFitness.h"
void GeneticAlgorithm::run(Star* star) 
{


	// the size of the initial genotype
	const int INIT_GENOTYPE_SIZE = 10;

	RandomInitGenotype rig;
	Genotype geno;
	BitFlipMutation bitflip;
	CoverPercentRatioFitness fit;

	geno= rig.fillGenotype(star, INIT_GENOTYPE_SIZE);
	std::cout << "fillGenotype\n";
	std::cout << geno.toString() << "-------\n" << std::endl;


	bitflip.mutateGenotype(geno);
	std::cout << "mutateGenotype\n";
	std::cout << geno.toString() << "-------\n" << std::endl;

	fit.setFitness(geno);
	std::cout << "setFitness\n";
	std::cout << geno.toString() << "-------\n" << std::endl;
	

	

	system("pause");



	/*// loop until termination condition is met
	while (1 = 1) {

		// calulate the fitness
		if (!_fitness->start()) return false;

		// perform the cross over
		if (!_crossover.start()) return false;

		// mutate the genotype
		if (!_mutation.start()) return false;

	}*/

}


