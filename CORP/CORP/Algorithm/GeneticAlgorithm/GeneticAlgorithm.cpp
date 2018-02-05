/**
*  file:	GeneticAlgorithm.cpp
*  author:	Steven Gallagher
*  date:	12/05/2017
*  updated:	12/05/2017
*
*  Execute a genetic algorithm with the provided
*  genetic operators.
*
*
*/

#include"GeneticAlgorithm.h"
#include"GeneticOperator\InitGenotype\RandomInitGenotype\RandomInitGenotype.h"
#include"Genotype\Genotype.h"



#include"GeneticOperator\Crossover\OnePointCrossover\OnePointCrossover.h"
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
	OnePointCrossover cross;
	geno = rig.fillGenotype(star, INIT_GENOTYPE_SIZE);
	std::cout << "fillGenotype\n";
	std::cout << geno.toString() << "-------\n" << std::endl;
	int i = 0;
	while(true) {


		fit.setFitness(geno);
		Chromosome most_fit = geno.getMostFit();



		if (i % 100 == 0) {
			std::cout << "iteration:\t" << i << std::endl; 
			std::cout << geno.toString() << std::endl;
		}
		if (most_fit.getFitness() >= 0.15 &&
			most_fit.getCover()._bitVector.numberSelected() == 5
			&& most_fit.getCover().checkCover()
			
			)

		{
			
			std::cout << "SOLUTION FOUND!!!!!!   " << most_fit.getCover()._bitVector.numberSelected() << std::endl;
			std::cout << most_fit.getCover().toString() << std::endl;
			std::cout <<most_fit.getCover().coverPercent() << std::endl;
			std::cout << most_fit.getCover()._star->_matrix.toString();
			system("pause");
		}


		
		bitflip.mutateGenotype(geno);

		cross.performCrossover(geno, star);
		i++;

	}
	


	

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


