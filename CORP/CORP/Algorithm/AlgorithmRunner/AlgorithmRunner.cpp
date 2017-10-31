#include"AlgorithmRunner.h"


AlgorithmRunner::AlgorithmRunner(Algorithm* algorithm_to_run) : _algorithm { algorithm_to_run } {}


bool AlgorithmRunner::start(Cover& cover) {
	return _algorithm->run(cover);

}

