#ifndef _Algorithm_Guard_
#define _Algorithm_Guard_ 1
#include"../Matrix/matrix.hpp"
class Algorithm {

private:


protected:
	Algorithm();

public:

	virtual bool run(std::Matrix<int>()) = 0;

	
};


#endif
