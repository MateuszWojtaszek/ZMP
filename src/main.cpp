#include <iostream>
#include "AbstractInterp4Command.hh"
#include "LibInterface.hpp"
#include "PluginManager.hpp"
#include "xmlinterp.hh"
// instead of using namespace std
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int main() {
  //! ************** TEST PREPROCESORA **************//
  // std::istringstream preprocessed_content;
  // const char* filename = "../src/cpp_test.txt";

  // if (preprocesFile(filename, preprocessed_content)) {
  //   std::cout << "Wstępnie przetworzona zawartość pliku:\n\n";

  //   // Odczytujemy i wyświetlamy zawartość strumienia
  //   std::string line;
  //   while (std::getline(preprocessed_content, line)) {
  //     std::cout << line << "\n";
  //   }
  // }
  //! ************** TEST PREPROCESORA **************//

  Configuration Config;

  if (!ReadFile("config/config.xml", Config))
    return 1;
  PluginManager manager;
  for (auto libNames : Config.getAllLibNames()) {
    manager.addNewPlugin(libNames);
  }
  // --- ETAP 2: Pętla testująca menedżera ---
  std::vector<std::string> commandsToTest = {"Move", "Rotate", "Pause", "Set"};

  using createCmdFunctionPtr = AbstractInterp4Command* (*)(void);

  for (const std::string& cmdName : commandsToTest) {
    cout << "\n****************************" << endl;
    cout << "Testowanie polecenia: " << cmdName << endl;

    // 1. Znajdź fabrykę w menedżerze
    LibInterface* pFactory = manager.getPlugin(cmdName);

    if (pFactory == nullptr) {
      cerr << "!!! BŁĄD: Nie znaleziono wtyczki dla '" << cmdName << "'"
           << endl;
      continue;  // Przejdź do następnego testu
    }

    // 2. Pobierz funkcję tworzącą
    createCmdFunctionPtr pCreateCmd = pFactory->getCreatedCmd();
    if (pCreateCmd == nullptr) {
      cerr << "!!! BŁĄD: Fabryka dla '" << cmdName
           << "' nie ma funkcji CreateCmd!" << endl;
      continue;
    }

    // 3. Utwórz instancję polecenia (używając unique_ptr dla bezpieczeństwa)
    std::unique_ptr<AbstractInterp4Command> pCmd(pCreateCmd());

    // 4. Wywołaj metody na poleceniu, aby potwierdzić, że działa
    cout << "  Nazwa polecenia (z obiektu): " << pCmd->GetCmdName() << endl;

    cout << "  Składnia:" << endl;
    pCmd->PrintSyntax();

    cout << "  Przykładowe wywołanie:" << endl;
    pCmd->PrintCmd();
  }
  cout << "\n--- Zakończono testowanie ---" << endl;
  return 0;
}
