/*
*  file:	CoverPercentRatio.cpp
*  author:	Steven Gallagher
*  date:	12/05/2017
*  updated:	1/30/2017
*
* get fitness based on cover percent and number selected
*
*/

#include "CoverPercentRatioFitness.h"

// set the fitness of each chromosome in the genotype with their cover percent
// divided by the solution size
bool CoverPercentRatioFitness::setFitness(Genotype& genotype)
{

	for (Chromosome& chromo : genotype.getChromosomes()) 
	{

		int numselection = chromo.getCover()._bitVector.numberSelected();
		chromo.setFitness(chromo.getCover().coverPercent()/numselection);
	}

	return true;
}

