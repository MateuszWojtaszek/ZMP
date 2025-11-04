#pragma once
#include <map>
#include <memory>
#include "LibInterface.hpp"
class PluginManager {
  std::map<std::string, std::shared_ptr<LibInterface>> _plugins;

 public:
  void addNewPlugin(const std::string& pluginFileName);
  LibInterface* getPlugin(const std::string& pluginName);
};