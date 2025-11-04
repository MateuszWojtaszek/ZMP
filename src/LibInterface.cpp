#include "LibInterface.hpp"

LibInterface::LibInterface(const char* plugin)
    : _LibHandler(dlopen(plugin, RTLD_LAZY)) {
  if (!_LibHandler) {
    const char* error_msg = dlerror();
    std::string full_error = "Błąd ładowania wtyczki '";
    full_error += plugin;
    full_error += "': ";
    full_error += (error_msg ? error_msg : "Nieznany błąd dlopen");
    throw std::runtime_error(full_error);
  }
  void* tmp_pFun = dlsym(_LibHandler, "CreateCmd");
  if (!tmp_pFun) {
    dlclose(_LibHandler);
    throw std::runtime_error("Błąd: Brak symbolu 'CreateCmd' w wtyczce.");
  }
  _pCreateCmd = reinterpret_cast<createCmdFunctionPtr>(tmp_pFun);
  void* tmp_cName = dlsym(_LibHandler, "GetCmdName");
  if (!tmp_cName) {
    dlclose(_LibHandler);
    throw std::runtime_error("Błąd: Brak symbolu 'GetCmdName' w wtyczce.");
  }
  createCmdNamePtr tmp = reinterpret_cast<createCmdNamePtr>(tmp_cName);

  _CmdName = tmp();
}
LibInterface::~LibInterface() {
  dlclose(_LibHandler);
}