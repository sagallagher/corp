#define _CRTDBG_MAP_ALLOC
#include<iostream>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

#include"AlgorithmSelect.h"
#include"../AlgorithmRunner/AlgorithmRunner.h"



AlgorithmSelect::AlgorithmSelect(const Cover& cover, const Config* config) :
    _cover{ cover }, _config{config}
{}


//AlgorithmRunner AlgorithmSelect::selectAlgorithm(const std::string& choice)
//{
//	if (choice == "NaiveAlgorithm")
//    {
//		AlgorithmRunner runner(new NaiveAlgorithm());
//
//        runner.start(_cover, _config);
//
//        return runner;
//	}
//}
