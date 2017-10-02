#include"CppUnitTest.h"
#include"../../CORP/OptionContainer/OptionContainer.h"
//#include"../OptionContainer/TEST_OptionContainer.cpp"
#include"../../CORP/Config/Config.h"
#include<iostream>
#include<fstream>


bool insertRandomSpace2(std::string& input) {
	if (input.length() == 0) { return false; }
	input[rand() % input.length()] = ' ';
	return true;
}

std::string generateRandomKey2() {
	char randomChar;
	std::string key = "";

	for (int i = 0; i < rand() % 100 + 1; i++) {
		key += (rand() % 26 + 97);
		insertRandomSpace2(key);
	}
	return key;
}

std::vector<std::string> getKeyVector2(int keysToGenerate) {
	std::vector<std::string> keys;

	for (int i = 0; i < keysToGenerate; i++) {
		keys.push_back(generateRandomKey2());
	}
	return keys;
}




// generate a random config file
bool generateTestConfigFile(std::string fileToUse, std::vector<std::string> keys) {
	
	// create ofstream object
	std::fstream cfg;
	cfg.open(fileToUse);
	if (!cfg) return false;

	// write int keys
	for (int i = 0; i < keys.size()/3; i++) {
		cfg << keys.at(i) + "=" + "1";
	}


	// write bool keys
	for (int i = keys.size() / 3; i < (2.0/3) * keys.size() ; i++) {
		cfg << keys.at(i) + "=" + "true";
	}

	// close config
	cfg.close();
	
	return true;
}


bool readTestConfigFile(std::string fileToUse, std::vector<std::string> keys) {
	// simulate command line arguments
	int argc = 1;
	char const *argv[2];
	argv[0] = "main.cpp";
	argv[1] = fileToUse.c_str();
	generateTestConfigFile(argv[1],keys);
	return Config::initialize(argc, argv);
}

// ensure all values are as they should be
bool checkValues(std::string fileToUse,int keysToUse) {
	bool result = false;

	std::vector<std::string> keys = getKeyVector2(keysToUse);
	if(!generateTestConfigFile(fileToUse, keys)) return false;
	if(!readTestConfigFile(fileToUse,keys)) return false;

	// check int values
	for (int i = 0; i < keys.size() / 3;i++) {
		if (Config::getInstance()->pull(keys.at(i), "0") == 1) result = true;
	}

	// check bool values
	for (int i = keys.size() / 3; i < keys.size() * (2.0/3); i++) {
		if (Config::getInstance()->pull(keys.at(i), "false") == true) result = true;
	}

	return result;
}


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CORP
{		
	TEST_CLASS(Config)
	{
	public:

		TEST_METHOD(parse)
		{
			Assert::AreEqual(true,::checkValues("test_config.txt",10));
		}

	};
}