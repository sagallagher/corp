#include"AlgorithmRunner.h"


AlgorithmRunner::AlgorithmRunner(Algorithm* algorithm_to_run) : _algorithm { algorithm_to_run }{

}

void AlgorithmRunner::repair(Cover& cover) {
	_cover = cover;
}

bool AlgorithmRunner::start() {
	return _algorithm->run(_cover);

}

