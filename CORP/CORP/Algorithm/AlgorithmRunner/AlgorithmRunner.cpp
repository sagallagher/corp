#define _CRTDBG_MAP_ALLOC
#include<iostream>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif


#include"AlgorithmRunner.h"


AlgorithmRunner::AlgorithmRunner(Algorithm* algorithm_to_run) : _algorithm { algorithm_to_run } {}


bool AlgorithmRunner::start(Cover& cover) {
	return _algorithm->run(cover);

}

