#include "Config.h"
#include<iostream>
#include<algorithm>
#include <string.h>



Config::Config(std::string cfg_file_name) : _cfg_file_path{ cfg_file_name } {}


// Return the value of a key
// value is returned if the key is not found
int Config::pull(const std::string &key, const std::string &value) const {

  if(_option_container.isInt(value))  {
    return _option_container.pullInt(key,value);
  }

}

// IN PROGRESS
bool Config::parse() {

  std::ifstream cfg(_cfg_file_path.c_str());

  if(!cfg) {
    std::cerr << "Could not find congiguration file";
  }

  char key[256];
  char value[32];

  while(!cfg.eof()) {
      cfg.getline(key,256,'=');
      cfg.getline(value,32,'\n');
      std::pair<std::string,std::string> new_option = std::make_pair(key,value);
      _option_container.push(key,value);
  }

}
