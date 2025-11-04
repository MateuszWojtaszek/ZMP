#ifndef CONFIGURATION_HH
#define CONFIGURATION_HH
#include <iostream>
#include <vector>

class Configuration {
  std::vector<std::string> _cmdNames;

 public:
  void addLibToConfiguration(const std::string& libname) {
    _cmdNames.push_back(libname);
  }
  void printAllLibInConfiguration() const {
    for (auto name : _cmdNames) {
      std::cout << name << "\n";
    }
  }
  const std::vector<std::string>& getAllLibNames() const { return _cmdNames; }
};

#endif
