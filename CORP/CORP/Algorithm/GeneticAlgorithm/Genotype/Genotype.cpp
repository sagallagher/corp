#include"Genotype.h"
#include<sstream>


// return the genotype as a vector of chromosomes
std::vector<Chromosome>& Genotype::getChromosomes() { return _chromosomes; }


// add a chromosome to the genotype
bool Genotype::appendChromosome(Chromosome& chromosome)
{
	_chromosomes.push_back(chromosome);
	return true;
}

// string representation of a genotype
std::string Genotype::toString() {
	std::string result = "";

	for (Chromosome chrom : getChromosomes()) {

		std::ostringstream strs;
		strs << chrom.getFitness();
		std::string str = strs.str();
		result += (chrom.getCover().toString() + "\t|\t" + str +"\n");
	}
	return result;

}