#ifndef _Algorithm_Guard_
#define _Algorithm_Guard_ 1
#include"../Matrix/matrix.hpp"
#include"../Cover/Cover.h"
#include<vector>

class Algorithm {

public:

	virtual bool run(Cover& cover) = 0;
	virtual std::vector<std::vector<int>> getSolutionSet() = 0;

protected:
	Cover _cover;
	std::vector<std::vector<int>> _solution_set;

};

#endif
