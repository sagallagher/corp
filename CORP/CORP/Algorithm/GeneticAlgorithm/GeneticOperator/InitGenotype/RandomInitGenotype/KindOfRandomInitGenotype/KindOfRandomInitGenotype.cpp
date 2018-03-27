#include"KindOfRandomInitGenotype.h"
#include<fstream>
#include"../../../../Genotype/Chromosome/Chromsome.h"
#include"../../../../../../Config/Config.h"

// returns genotype filled with solutions from text file
// fills the rest with random chromosomes
Genotype KindOfRandomInitGenotype::fillGenotype(Star* star, int size)
{
	// number of times to mutate each generation
	std::string CHROMOSOME_FILE = "chromosomes.txt";
	CHROMOSOME_FILE = Config::getInstance()->pull("CHROMOSOME_FILE", CHROMOSOME_FILE);

	fillGenotypeFromFile(CHROMOSOME_FILE, star);

	fillRest(size,star);

	return _genotype;
}


void KindOfRandomInitGenotype::fillRest(int size, Star* star)
{
	while (_genotype.getChromosomes().size() < size)
	{
		_genotype.appendChromosome(RandomInitGenotype::getRandomChromosome(star));
	}
}

// loop through file and make chromosomes to append to genotype
bool KindOfRandomInitGenotype::fillGenotypeFromFile(std::string file_path, Star* star)
{
	std::ifstream chromo_file(file_path);

	std::string line;

	int index;

	while (std::getline(chromo_file, line))
	{

		Cover temp_cover(star);

		Chromosome new_chromo(temp_cover);

		index = 0;

		for (char vertex : line)
		{
			if (vertex == '1') new_chromo.getCover().select(index);

			index++;
		}
		
	}

	return true;
}

