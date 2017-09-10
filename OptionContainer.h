#ifndef _OPTION_CONTAINER_GAURD_
#define  _OPTION_CONTAINER_GAURD_

#include<vector>
#include<string>


class OptionContainer {

private:
  std::vector<std::pair<std::string, int>> _intOptions;
  std::vector<std::pair<std::string, bool>> _boolOptions;

public:
  // is value is an int?
  bool isInt(const std::string value) const;

  // is value a bool?
  bool isBool(const std::string value) const;

  // push a value to the correct container
  bool push(const std::string& key,const std::string& value);

  // pull a key's int value
  int pullInt(const std::string& key, const std::string& value) const;

  // pull a key's bool value
  bool pullBool(const std::string& key, const std::string& value) const;

  // does the key exist in any container?
  bool key_exists(const std::string& key) const;

};

#endif
