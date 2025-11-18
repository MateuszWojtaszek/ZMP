#include <functional>
#include <iostream>
#include <limits>
#include <memory>
#include <sstream>
#include <thread>
#include <vector>
#include "AbstractInterp4Command.hh"
#include "ComChannel.hpp"
#include "LibInterface.hpp"
#include "MobileObj.hpp"
#include "PluginManager.hpp"
#include "Port.hh"
#include "Scene.hpp"
#include "ppf.hpp"
#include "xmlinterp.hh"
// instead of using namespace std
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
struct ThreadTask {
  std::unique_ptr<AbstractInterp4Command> pCmd;
  std::string objName;
};

int main() {
  using createCmdFunctionPtr = AbstractInterp4Command* (*)(void);
  Configuration Config;
  std::string cmdName;
  std::string objName;
  PluginManager manager;
  ComChannel channel;
  bool inParallel = false;
  std::vector<ThreadTask> tasks;
  if (!ReadFile("config/config.xml", Config))
    return 1;

  for (auto libNames : Config.getAllLibNames()) {
    manager.addNewPlugin(libNames);
  }
  std::istringstream preprocessed_content;
  const char* filename = "../config/opis_dzialan.cmd";

  if (preprocesFile(filename, preprocessed_content)) {
    std::cout << "Przetworzono komendy przez preprocesor\n";
  }
  if (!channel.OpenConnection(PORT)) {
    std::cerr << " Nie udało się nawiązać połączenia z serwerem \n";
    return 0;
  }
  channel.Send("Clear\n");
  Scene scene;
  for (const auto& cfg : Config.getCubeConfigs()) {
    // 1. Tworzymy obiekt lokalny i ustawiamy mu parametry
    MobileObj* pObj = new MobileObj();
    pObj->SetName(cfg.Name.c_str());
    pObj->SetPosition_m(cfg.Trans_m);
    pObj->SetShift(cfg.Shift);
    pObj->SetScale(cfg.Scale);
    pObj->SetRGB(cfg.RGB);
    pObj->SetAng_Roll_deg(cfg.RotXYZ_deg[0]);
    pObj->SetAng_Pitch_deg(cfg.RotXYZ_deg[1]);
    pObj->SetAng_Yaw_deg(cfg.RotXYZ_deg[2]);

    // tu jest opakowanie w shared_ptr
    scene.AddMobileObj(pObj);

    // 2. Budujemy komende AddObj dla serwera
    std::stringstream ss;
    ss << "AddObj Name=" << cfg.Name << " RGB=(" << cfg.RGB[0] << ","
       << cfg.RGB[1] << "," << cfg.RGB[2] << ")"
       << " Scale=(" << cfg.Scale[0] << "," << cfg.Scale[1] << ","
       << cfg.Scale[2] << ")"
       << " Shift=(" << cfg.Shift[0] << "," << cfg.Shift[1] << ","
       << cfg.Shift[2] << ")"
       << " RotXYZ_deg=(" << cfg.RotXYZ_deg[0] << "," << cfg.RotXYZ_deg[1]
       << "," << cfg.RotXYZ_deg[2] << ")"
       << " Trans_m=(" << cfg.Trans_m[0] << "," << cfg.Trans_m[1] << ","
       << cfg.Trans_m[2] << ")"
       << "\n";  // Bardzo wazne \n na koncu!

    cout << "Wysylam: " << ss.str();  // Debug
    channel.Send(ss.str().c_str());
  }

  while (preprocessed_content >> cmdName) {
    if (cmdName == "Begin_Parallel_Actions") {
      inParallel = true;
    } else if (cmdName == "End_Parallel_Actions") {
      inParallel = false;
      cout << "--- Startuje blok rownolegly (" << tasks.size() << " watkow) ---"
           << endl;
      std::vector<std::thread> threads;  // tworze wektor wątkow
      // 1. Uruchamianie watkow
      for (const auto& task : tasks) {
        // przekazuje zadanie, scene i kanal
        threads.emplace_back([&task, &scene, &channel]() {
          // Wypisanie info (opcjonalnie, z mutexem na cout byloby bezpieczniej)
          // task.pCmd->PrintCmd();

          // Wykonanie wlasciwej komendy w watku
          if (!task.pCmd->ExecCmd(scene, task.objName.c_str(), channel)) {
            cerr << "!!! Blad w watku dla obiektu: " << task.objName << endl;
          }
        });
      }
      for (auto& th : threads) {
        if (th.joinable()) {
          th.join();
        }
      }
      tasks.clear();
      cout << "--- Koniec bloku rownoleglego ---" << endl;
    } else {
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
      if (inParallel == true) {
        tasks.push_back({std::move(pCmd), objName});
      } else {
        cout << "Wczytano polecenie: " << cmdName << " " << objName << " ";
        pCmd->PrintCmd();
        if (!pCmd->ExecCmd(scene, objName.c_str(), channel)) {
          cerr << "!!! Błąd podczas wykonywania polecenia: " << cmdName << endl;
        }
      }
    }
    preprocessed_content.ignore(
        std::numeric_limits<std::streamsize>::max(),
        '\n');  // pominięcie smieci jesli preprocesor cos zostawi
  }
  channel.Close();
  cout << "--- Zakończono przetwarzanie pliku z komendami ---" << endl;
}
