To use Visual Studio:
1. Open CORP.sln
2. In the Solution Explorer, right click "Solution 'CORP' (2 projects) and select "Properties"
3. Under "Common Properties", be sure "Single startup project" is selected
3. Click on the drop down menu below the "Single startup project" radio box, select CORP2.
4. Press OK

5. In the Solution Explorer, right click CORP2 and select "Properties"
6. Under "Configuration Properties", select "Debugging"
7. For the field "Command Arguments", supply the path to a configuration file
8. Press Ok


InputParser
  InputParser parses a configuration file into an OptionsContainer.

OptionsContainer
  OptionsContainer is a variable length data structure for multiple different
  data types.

Logger
  Logger is used to write text to files and display text in the console.

Config.cpp
  Config uses a singleton design pattern to offer easy access
  across classes to values parsed using InputParser.

Matrix
  Matrix is a 1D representation of a 2D matrix.

Star
  Star stores data regarding the current adjacency list we are
  working with.

BoolSet
  A wrapper of star for this specific problem.

Cover
  Cover offers methods to interact with a BoolSet.

Algorithm
  Algorithm provides functions to assist with running algorithms.

AlgorithmRunner
  AlgorithmRunner provides an environment to run algorithms.

Executor
  Executor allows for easy substitution of algorithm to run.

BeamSearch
  BeamSearch recurses the depth of the tree until a solution is found while
  exploring the width of a given branching factor.

GeneticAlgorithm
  GeneticAlgorithm applies the provided genetic operators.

Chromosome
  Chromosome is a representation of a solution in the genetic algorithm.

Genotype
  A genotype is a container for chromosomes.

InitGenotype
  InitGenotype is a pure virtual class to define the functions a child of
  InitGenotype will overwrite. This class is used to initialize a genotype.

RandomInitGenotype
    RandomInitGenotype is an InitGenotype where a genotype is randomly filled with
    a provided number of chromosomes.

KindOfRandomInitGenotype
  KindOfRandomInitGenotype is an InitGenotype that initializes a genotype using
  solutions listed in a given text file. If the number of solutions provided in
  this text file does not match the desired genotype size, the remainder of the
  genotype will be filled with randomly generated chromosomes.

Crossover
  Crossover is a pure virtual class to define the functions a child of
  Crossover will overwrite. This class is used to generate offspring and select
  the chromosomes that will advance to the next generation.

OnepointCrossover
  OnepointCrossover is a crossover that selects the two strongest chromosomes and
  a random pivot in the range of the length of these chromosomes. The tail ends of
  the two strongest chromosomes are swapped to generate two offspring. These two
  offspring then replace the 2 weakest chromosomes in the genotype for the next
  generation.

Mutation
  Mutation is a pure virtual class to define the functions a child of
  Mutation will overwrite. This class is used to slightly modify each chromosome
  in a given genotype.

BitFlipMutation
  BitFlipMutation is a Mutation that selects a random bit in each chromosome of a given genotype
  negates it.

Fitness
  Fitness is a pure virtual class to define the functions a child of
  Fitness will overwrite. This class is used to calculate and set the fitness of
  each chromosome in a given genotype.

ColoringFitness
  ColoringFitness is a Fitness that uses the number selected, the cover percent,
  and the number of colors used to determine the fitness of each chromosome in a
  given genotype.

CoverPercentFitness
  ColoringFitness is a Fitness that uses the number selected and the cover
  percent to determine the fitness of each chromosome in a given genotype.
