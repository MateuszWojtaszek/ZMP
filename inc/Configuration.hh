#ifndef CONFIGURATION_HH
#define CONFIGURATION_HH
#include <Vector3D.hh>
#include <iostream>
#include <string>
#include <vector>
struct ConfigCube {
  std::string Name;
  Vector3D Shift;
  Vector3D Scale;
  Vector3D RotXYZ_deg;
  Vector3D Trans_m;
  Vector3D RGB;
  ConfigCube() {
    Scale[0] = 1;
    Scale[1] = 1;
    Scale[2] = 1;
    RGB[0] = 128;
    RGB[1] = 128;
    RGB[2] = 128;
  }
};

class Configuration {
  std::vector<std::string> _libNames;
  std::vector<ConfigCube> _cubeConfigs;

 public:
  void addLibToConfiguration(const std::string& libname) {
    _libNames.push_back(libname);
  }
  void printAllLibInConfiguration() const {
    for (const auto& name : _libNames) {
      std::cout << name << "\n";
    }
  }
  const std::vector<std::string>& getAllLibNames() const { return _libNames; }
  void addNewCubeConfig(const ConfigCube& rCube) {
    _cubeConfigs.push_back(rCube);
  }
  const std::vector<ConfigCube>& getCubeConfigs() const { return _cubeConfigs; }
};

#endif
