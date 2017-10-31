#include"AlgorithmSelect.h"
#include"../AlgorithmRunner/AlgorithmRunner.h"



AlgorithmSelect::AlgorithmSelect(Cover& cover) : _cover{ cover } {}

Algorithm* AlgorithmSelect::selectAlgorithm(std::string choice) {
	if (choice == "NaiveAlgorithm") {
		NaiveAlgorithm* alg = new NaiveAlgorithm;
		AlgorithmRunner runner(alg);
		runner.start(_cover);
		return alg;
	}
}
