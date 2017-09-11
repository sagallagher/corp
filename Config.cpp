#include"Config.h"
#include<iostream>
#include<fstream>
#include<cstring>
#include<utility>
Config::Config(std::string cfg_file_name) { parse(cfg_file_name); }

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
