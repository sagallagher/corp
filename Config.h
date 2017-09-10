#ifndef _CONFIG_
#define _CONFIG_

#include"OptionContainer.h"
#include<fstream>
#include<string.h>

class Config {

private:
  // Member variables
  std::string _cfg_file_path;
  OptionContainer _option_container;

public:
  // store the location of the config file
  Config(std::string cfg_file_path);

  // parse config file
  bool parse();

  // pull a value of a key
  int pullInt(const std::string &key, const int &value) const;

};

#endif
