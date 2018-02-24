/*
*  file:	CoverPercentRatio.cpp
*  author:	Steven Gallagher
*  date:	12/05/2017
*  updated:	1/30/2017
*
* get fitness based on cover percent and number selected
*
*/
#include<math.h>
#include "CoverPercentRatioFitness.h"

// set the fitness of each chromosome in the genotype with their cover percent
// divided by the solution size
bool CoverPercentRatioFitness::setFitness(Genotype& genotype)
{
	float n;
	float p;
	for (Chromosome& chromo : genotype.getChromosomes()) 
	{
		p = chromo.getCover().coverPercent()*100;
		n = (chromo.getCover()._bitVector.numberSelected());

		chromo.setFitness(10*p - pow(n, 1+(p/250)));
	}

	return true;
}

