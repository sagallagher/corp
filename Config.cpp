#include"Config.h"
#include<iostream>
#include<fstream>
#include<cstring>
#include<utility>

Config::Config() {}

Config::~Config() {
  delete _instance;
}

bool Config::initialize(int argc,const char** cmdparams) {

  // ensure atleast one command line argument was provided
  if (argc == 2) {
    std::cerr << "Configuration file required\n";
    exit(-1);
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
Config* Config::getInstance() {
  return _instance;
}

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

  char key[256];
  char value[32];

  while(!cfg.eof()) {

    // store the characters from the beginning of the line to the '=' character
    cfg.getline(key,256,'=');

    // if the line is not a comment, push the attribute to OptionContainer
    if (key[0] != '#') {

      // store the rest of the line as the value
      cfg.getline(value,32,'\n');

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
