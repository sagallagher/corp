#include<iostream>
#include"Config/Config.h"
#include"OptionContainer/OptionContainer.h"

Config* Config::_instance = 0;

int main(int argc, char const *argv[]) {

	Config::initialize(argc, argv);

	return 0;
}
