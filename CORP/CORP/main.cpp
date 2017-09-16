#include<iostream>
#include"Config.h"
#include"OptionContainer.h"

Config* Config::_instance = 0;

int main(int argc, char const *argv[]) {

	Config::initialize(argc, argv);

	return 0;
}
