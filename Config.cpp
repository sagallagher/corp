#include"Config.h"
#include<iostream>

Config::Config(std::string cfg_file_name) { parse(cfg_file_name); }

// parse config file
bool Config::parse(std::string cfg_file_path) {

  std::ifstream cfg(cfg_file_path.c_str());

  if(!cfg) {
    std::cerr << "Could not find configuration file";
    return false;
  }

  char key[256];
  char value[32];

  while(!cfg.eof()) {
      cfg.getline(key,256,'=');
      cfg.getline(value,32,'\n');
      std::pair<std::string,std::string> new_option = std::make_pair(key,value);
      push(key,value);
  }

  cfg.close();

  return true;

}
