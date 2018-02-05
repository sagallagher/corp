/**
 *  Main execution class.
 *     (a) Given an input file name
 *     (b) Parse
 *     (c) Run algorithm
 *     (d) Report
 *     (e) Clean up
 *
 *  @author C. Alvin, et. al.
 */
#ifndef _EXECUTOR_GUARD
#define _EXECUTOR_GUARD

#define _CRTDBG_MAP_ALLOC
#include<iostream>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

#include "../CORP/Config/Config.h"
#include "../CORP/InputParser/InputParser.h"
#include "../CORP/Matrix/Matrix.hpp"
#include "../CORP/Cover/Cover.h"
#include "../CORP/Star/Star.h"
#include "../CORP/Algorithm/AlgorithmSelect/AlgorithmSelect.h"
#include "../CORP/Algorithm/AlgorithmRunner/AlgorithmRunner.h"
#include "../CORP/Algorithm/GeneticAlgorithm/GeneticAlgorithm.h"
#include"../CORP2/Validator.hpp"

class Executor
{
protected:
    // Input file stream: adjacency
    std::ifstream _ifs;

    // The resulting adjacency matrix
    Matrix<int>* _matrix;

public:
    Executor(const std::string& infile) : _ifs{ infile }, _matrix{nullptr}
    {
        if (!_ifs) throw "Input file " + infile + " failed to open.";
    }

    virtual ~Executor()
    {
        cleanup();
    }

private:
    // Dynamic Memory Deallocation and closings
    void cleanup()
    {
        delete _matrix;
        Config::cleanUp();
    }

public:
    void execute()
    {
        // Acquire the input matrix
        parse();

        // Execute an algorithm
        run();
    }

private:
    //
    // Parse and acquire the adjacency matrix
    //
    void parse()
    {
        InputParser parser{ _ifs };
        _matrix = parser.parse();
        std::cout << "Parsing complete." << std::endl;
    }

    //
    // Execute the algorithm over the input matrix
    //
    void run()
    {
        // choose an algorithm and display the solution set
        AlgorithmRunner<GeneticAlgorithm> runner;

        Star* star = new Star(*_matrix);

		Cover cover(star);
		Validator val;
		std::vector<int> sol = { 2 ,3 ,21, 23, 24 };
		std::cout << "IS SOLUTION?\t" << val.checkSolution(cover, sol) << std::endl;
		system("pause");
		

		

        runner.start(star);

        delete star;
		std::cout << "SOLUTIONS";
        std::cout << runner.toString();
    }
};

#endif