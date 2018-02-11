#define _CRTDBG_MAP_ALLOC
#include<iostream>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

#include"../CORP2/Validator.hpp"
#include "../CORP2/Executor.hpp"

const std::string DEFAULT_INPUT = "../../data/24cell_facets.txt";
const std::string DEFAULT_SOLUTION_SET = "../../data/24cell_corelist.txt";

int main(int argc, const char* argv[])

{
	Validator valid;
	Cover cover;


    if (!Config::initialize(argc, argv))
    {
        std::cerr << "Config file could be parsed; exiting." << std::endl;
        system("pause");
        return 1;
    }

    Executor* executor = new Executor{ Config::getInstance()->pull("AdjacencyList", DEFAULT_INPUT) };

    executor->execute();

    delete executor;

	std::cout << " dumping\n";
    system("pause");

    std::cout << "Dumping Memory Leaks" << std::endl;
    _CrtDumpMemoryLeaks();
}