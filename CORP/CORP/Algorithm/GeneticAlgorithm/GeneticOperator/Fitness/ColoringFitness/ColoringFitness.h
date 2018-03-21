#include "../Fitness.h"

class ColoringFitness : public Fitness {

public:
	bool setFitness(Genotype &);

private:

	int getChromaticNumber(Chromosome&);

};