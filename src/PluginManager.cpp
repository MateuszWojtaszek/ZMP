#include "PluginManager.hpp"

void PluginManager::addNewPlugin(const std::string& pluginFileName) {
  try {
    auto newPlugin = std::make_shared<LibInterface>(pluginFileName.c_str());
    std::string cmdName = newPlugin->getCmdName();
    _plugins[cmdName] = newPlugin;
    std::cout << "Załadowano wtyczkę: " << cmdName
              << " (z pliku: " << pluginFileName << ")" << std::endl;
  } catch (const std::exception& e) {
    std::cerr << "Błąd podczas ładowania wtyczki " << pluginFileName << ": "
              << e.what() << std::endl;
  }
}

LibInterface* PluginManager::getPlugin(const std::string& pluginName) {
  auto it = _plugins.find(pluginName);
  if (it != _plugins.end()) {
    return it->second.get();
  }
  return nullptr;
}