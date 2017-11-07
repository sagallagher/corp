#ifndef _Algorithm_Guard_
#define _Algorithm_Guard_ 1
#include"../Matrix/matrix.hpp"
#include"../Cover/Cover.h"
#include<vector>

class Algorithm {

public:

	// every algorithm should overwrite this and use run() as the function to start the algorithm
	virtual bool run(Cover& cover) = 0;



	// output toString to a text file
	void write(std::string file_path);

protected:

	// used to store all solutions found by an algorithm
	std::vector<std::vector<int>> _solution_set;

};

#endif
