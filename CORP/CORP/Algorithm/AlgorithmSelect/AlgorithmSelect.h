#include<string>
#include"../../Cover/Cover.h"
#include"../Algorithm.h"
#include "../AlgorithmRunner/AlgorithmRunner.h"

class AlgorithmSelect {

public:
	AlgorithmSelect(Cover& cover);

	AlgorithmRunner* selectAlgorithm(std::string choice);
	

private:
	Cover _cover;

};