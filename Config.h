#ifndef _CONFIG_
#define _CONFIG_

#include"OptionContainer.h"
#include<string.h>

class Config : public OptionContainer {

private:
  // parse config file
  bool parse(std::string& cfg_file_name);

public:
  // store the location of the config file
  Config(std::string cfg_file_path);
};

#endif
