#include<string>
#include"../../Cover/Cover.h"
#include"../Algorithm.h"
#include "../AlgorithmRunner/AlgorithmRunner.h"
#include<vector>

class AlgorithmSelect {

public:
	AlgorithmSelect(Cover& cover);

	AlgorithmRunner selectAlgorithm(std::string choice);
	

private:
	Cover _cover;

};