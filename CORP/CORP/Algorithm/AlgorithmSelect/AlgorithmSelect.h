#include<string>
#include"../../Cover/Cover.h"
#include"../Algorithm.h"

class AlgorithmSelect {

public:
	AlgorithmSelect(Cover& cover);
	Algorithm* selectAlgorithm(std::string choice);
	

private:
	Cover _cover;

};