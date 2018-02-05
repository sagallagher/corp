/*
*  file:	CoverPercentRatio.h
*  author:	Steven Gallagher
*  date:	12/05/2017
*  updated:	1/30/2017
*
* get fitness based on cover percent and number selected
*
*/

#include"../Fitness.h"
#include"../../GeneticOperator.h"

class CoverPercentRatioFitness : Fitness {

public:
	
	// return the percent 
	bool setFitness(Genotype&);

};