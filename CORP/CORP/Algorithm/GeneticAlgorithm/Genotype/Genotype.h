#ifndef _GENOTYPE_GUARD_
#define  _GENOTYPE_GUARD_

class Genotype {

private:
  std::vector<Chromosome> _chromosomes;
  std::vector<Chromosome> _parents;
  std::vector<Chromosome> _offspring;

public:
  std::vector<Chromosome> getChromosomes();
  std::vector<Chromosome> getParents();
  std::vector<Chromosome> getOffspring();
};

#endif
