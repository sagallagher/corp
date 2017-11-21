#ifndef _Algorithm_Guard_
#define _Algorithm_Guard_ 1

#include"../Matrix/matrix.hpp"
#include"../Cover/Cover.h"
#include<vector>
#include"../../Config/Config.h"

class Algorithm {

public:

	// every algorithm should overwrite this and use run() as the function to start the algorithm
	virtual std::vector<std::vector<int>> run(Cover& cover, Config* config) = 0;

};

#endif
