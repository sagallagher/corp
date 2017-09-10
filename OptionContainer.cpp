#include"OptionContainer.h"
#include<iostream>
#include<string.h>
#include<cstring>
#include<utility>

// return if value is an int or not
bool OptionContainer::isInt(const std::string value) const {

  if(std::atoi(value.c_str()) == 0 && value != "0") return false;

  return true;

}

// return if value is a bool or not
bool OptionContainer::isBool(const std::string value) const {

  if (value == "false" || value == "true") return true;

  return false;

}

// push a value to the corrent container
bool OptionContainer::push(const std::string& key,const std::string& value) {

  if(isInt(value)) {
      // create pair
      std::pair<std::string, int> new_option = std::make_pair(key, std::atoi(value.c_str()));

      // push to int_options
      _intOptions.push_back(new_option);

      return true;

  }

  // NEEED TO IMPLEMENT
  else if(isBool(value)) {
    int z  = 4;
    return true;
  }

  // NEED TO IMPLEMENT
  // if none of the above, return an error
  else {
    int za = 4;
  }


  return false;
}


int OptionContainer::pullInt(const std::string& key, const int& value) const {

  for(auto pair : _intOptions) {

    if(std::strcmp(std::get<0>(pair).c_str(), key.c_str()) == 0) {
      return std::get<1>(pair);
    }
  }
  return value;

}
