#include "ColoringFitness.h"
#include<math.h>

//  f(x) = x / (1 + abs(x))
float sigmoid(float x)
{
	return (x / (1+abs(x)));
}

bool ColoringFitness::setFitness(Genotype& geno) {

	float p, n, x, r, k;
	int c;
	float fit;


	// loop through each solution in population
	for (Chromosome& chromo : geno.getChromosomes())
	{
		// check chromatic number of each solution
		c = getChromaticNumber(chromo);

		// set the fitness of the chromosome
		p = chromo.getCover().coverPercent();
		n = ((float)chromo.getCover()._bitVector.numberSelected()/ chromo.getCover()._bitVector.length());

		x = 1; k = 1; r = 5;
		int a = chromo.getCover()._bitVector.numberSelected();


		fit = 100*p - a - pow(2,abs(32-a)) + c;

		chromo.setFitness(fit);

	}

	return true;
}

// check if element is in vector
bool contains(std::vector<int> list, int element)
{
	for (int x : list)
	{
		if (x == element) return true;
	}

	return false;
}

// return array of chromoatic numbers with each indice of this array
// representing the associated indicie of the position
// of the solution in the genotype
int ColoringFitness::getChromaticNumber(Chromosome& chromo)
{

	// paste in austins colorings into vectors
	std::vector<int> colors = {1,2,1,2,1,3,1,2,1,2,1,2,3,4,3,3,3,4,2,4,1,2,1,2,1,3,1,2,1,2,1,4,4,5,3,3,3,2,3,3,1,2,1,2,1,3,1,2,1,2,1,4,4,5,3,3,3,2,3,3,1,2,1,4,1,2,1,2,1,2,1,2,3,4,3,3,3,3,3,3,1,2,1,2,1,3,1,2,1,2,1,5,5,4,3,4,3,2,3,3,1,2,1,4,1,2,1,2,1,2,1,3,5,4,4,4,2,2,3,4,1,2,1,4,1,2,1,2,1,2,1,3,3,3,3,4,2,2,3,4,1,2,1,4,1,2,1,2,1,2,1,2,5,3,4,3,5,3,3,3,1,2,1,2,1,3,1,2,1,2,1,2,3,5,3,5,3,4,2,4,1,2,1,2,1,3,1,2,1,2,1,2,4,4,4,4,3,4,2,4,1,2,1,2,1,3,1,2,1,2,1,4,4,5,4,4,5,2,3,3,1,2,1,2,1,3,1,2,1,2,1,2,3,4,3,4,3,4,2,3,1,2,1,2,1,3,1,2,1,2,1,4,4,5,4,4,5,2,3,4,1,2,1,4,1,2,1,2,1,2,1,2,5,3,4,4,3,3,3,3,1,2,1,2,1,3,1,2,1,2,1,2,4,5,3,4,3,4,2,3,1,2,1,3,1,2,1,2,1,2,1,2,5,3,3,4,4,3,3,3,1,2,1,3,1,2,1,2,1,2,1,2,4,3,4,3,4,3,3,3,1,2,1,3,1,2,1,2,1,2,1,2,4,4,4,3,4,3,3,3,1,2,1,3,1,2,1,2,1,2,1,2,5,4,3,3,5,4,3,3,1,2,1,2,1,3,1,2,1,2,1,2,4,4,3,4,4,4,2,4,1,2,1,3,1,2,1,2,1,2,1,2,5,4,4,4,5,4,3,3,1,2,1,3,1,2,1,2,1,2,1,2,5,3,4,4,4,2,4,4,1,2,1,3,1,2,1,2,1,2,1,2,4,4,4,4,4,4,3,4,1,2,1,2,1,3,1,2,1,2,1,2,4,5,4,4,3,5,4,4,4,3,3,4,1,2,2,1,2,3,3,4,3,4,1,3,4,3,1,5,1,4,2,2,3,3,4,4,5,1,4,4,4,4,1,3,4,3,4,1,3,2,2,2,1,3,4,4,5,1,3,2,4,1,5,3,4,4,4,1,3,4,3,5,1,2,4,3,1,5,3,5,4,4,1,2,1,3,3,4,3,4,3,2,5,2,3,3,3,4,1,3,3,3,4,3,3,5,3,4,3,1,4,2,5,3,4,4,2,5,1,3,4,3,5,1,4,4,4,3 };
	// vector of all the colors used
	std::vector<int> colors_used = {};

	// loop through cover
	for (int i = 0; i < chromo.getCover()._bitVector.length(); i++)
	{

		// check if current vertice is on
		if (chromo.getCover()._bitVector[i] == 1)
		{

			// if it is, check what coloring group it falls into

			// check if color is in colors_used
			if (!contains(colors_used, colors[i])) colors_used.push_back(colors[i]);


			// otherwise do nothing
		}

		// return the size of colors_used

	}

	return colors_used.size();


}
