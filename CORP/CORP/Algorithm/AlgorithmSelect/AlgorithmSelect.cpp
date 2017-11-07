#define _CRTDBG_MAP_ALLOC
#include<iostream>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

#include"AlgorithmSelect.h"
#include"../AlgorithmRunner/AlgorithmRunner.h"



AlgorithmSelect::AlgorithmSelect(Cover& cover) : _cover{ cover } {}

AlgorithmRunner* AlgorithmSelect::selectAlgorithm(std::string choice) {
	if (choice == "NaiveAlgorithm") {
		NaiveAlgorithm* alg = new NaiveAlgorithm;
		AlgorithmRunner runner(alg);
		runner.start(_cover);
		AlgorithmRunner* result = &runner;
		return result;
	}
}
