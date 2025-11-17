#include <iostream>
#include <limits>
#include "AbstractInterp4Command.hh"
#include "LibInterface.hpp"
#include "PluginManager.hpp"
#include "ppf.hpp"
#include "xmlinterp.hh"
// instead of using namespace std
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int main() {
  using createCmdFunctionPtr = AbstractInterp4Command* (*)(void);
  Configuration Config;
  std::string cmdName;
  std::string objName;

  if (!ReadFile("config/config.xml", Config))
    return 1;
  PluginManager manager;
  for (auto libNames : Config.getAllLibNames()) {
    manager.addNewPlugin(libNames);
  }
  std::istringstream preprocessed_content;
  const char* filename = "../config/opis_dzialan.cmd";

  if (preprocesFile(filename, preprocessed_content)) {
    std::cout << "Przetworzono komendy przez preprocesor\n";
  }
  while (preprocessed_content >> cmdName) {
    objName = "";

    LibInterface* plugin = manager.getPlugin(cmdName);
    if (plugin == nullptr) {
      cerr << "!!! BŁĄD: Nie znaleziono wtyczki dla '" << cmdName << "'"
           << endl;
      preprocessed_content.ignore(std::numeric_limits<std::streamsize>::max(),
                                  '\n');
      continue;
    }
    createCmdFunctionPtr pCreateCmd = plugin->getCreatedCmd();
    if (pCreateCmd == nullptr) {
      cerr << "!!! Błąd: Plugin: " << cmdName << " nie ma funkcji CreateCmd!";
      preprocessed_content.ignore(std::numeric_limits<std::streamsize>::max(),
                                  '\n');
      continue;
    }
    std::unique_ptr<AbstractInterp4Command> pCmd(pCreateCmd());
    if (cmdName != "Pause") {
      preprocessed_content >> objName;
    }
    if (!pCmd->ReadParams(preprocessed_content)) {
      cerr << "!!! Błąd: Nie udało się wczytać parametrow do wtyczki!";
      preprocessed_content.ignore(std::numeric_limits<std::streamsize>::max(),
                                  '\n');
      continue;
    }
    cout << "Wczytano polecenie: " << cmdName << " " << objName << " ";
    pCmd->PrintCmd();
    preprocessed_content.ignore(
        std::numeric_limits<std::streamsize>::max(),
        '\n');  // pominięcie smieci jesli preprocesor cos zostawi
  }
  cout << "--- Zakończono przetwarzanie pliku ---" << endl;
}
