#include"Config.h"
#include<iostream>
#include<fstream>
#include<cstring>
#include<utility>

Config::Config() {}

Config::~Config() { delete _instance; }

bool Config::initialize(int argc,const char** cmdparams) {

  // ensure atleast one command line argument was provided
  if (argc == 1) {
    std::cerr << "Configuration file required\n";
    return false;
  }

  // if an instance already exists, delete it before creating a new one
  if(_instance) delete _instance;

  // create a new instance of Config
  _instance = new Config();

  // extract first parameter from cmd parameters and store it as a string
  std::string cfg_file_name = cmdparams[1];

  // parse the file path
  _instance -> parse(cfg_file_name);

  return true;
}

// return the instance of Config
Config* Config::getInstance() { return _instance; }

// parse config file, provide path to this file
bool Config::parse(std::string& cfg_file_path) {
  // open the configuration file
  std::ifstream cfg(cfg_file_path.c_str());

  // if there is a problem finding the configuration file, print an
  // error and return false
  if(!cfg) {
    std::cerr << "Could not find configuration file";
    return false;
  }

  std::string key;
  std::string value;
  std::string line;

  while(getline(cfg, line)) {
    // store the characters from the beginning of the line to the '=' character
    if(line[0] != '#' && line.find('=') != std::string::npos ) {

      key = line.substr(0,line.find("="));

      std::cout << "key[0]\t" << key[0]<< std::endl;

      // if the line is not a comment, push the attribute to OptionContainer
      value = line.substr(line.find("=")+1);

      std::cout << "key:\t" << key << "\tvalue:\t" << value << std::endl;
      // create a new key value pair to store in the OptionContiner
      std::pair<std::string,std::string> new_option = std::make_pair(key,value);

      // push the pair into OptionContainer
      push(key,value);
    }
  }

  // close the configuration file
  cfg.close();

  // if the key value pairs in the configuration file
  // were stored correctly, return true
  return true;
}
