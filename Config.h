// Provides an interface for the implementation of a Config object
#ifndef _CONFIG_
#define  _CONFIG_

#include "OptionContainer.h"
#include <fstream>

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
  int pull(const std::string &key, const std::string &value) const;

};

#endif
