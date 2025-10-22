#include <dlfcn.h>

#include <cassert>
#include <iostream>
#include <ppf.hpp>
#include "LibInterface.hpp"

#include "AbstractInterp4Command.hh"
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
#if defined(__APPLE__)
  const char* lib_name = "libInterp4Move.dylib";
#elif defined(__linux__)
  const char* lib_name = "libInterp4Move.so";
#else
#error "Unsupported platform"
#endif
  // auto libHandlerDeleter = [](void* libPtr) {
  //   if (libPtr) {
  //     dlclose(libPtr);
  //   }
  // };

  // std::unique_ptr<void, decltype(libHandlerDeleter)> pLibHnd_Move(
  //     dlopen(lib_name, RTLD_LAZY), libHandlerDeleter);

  // using createCmdFunctionPtr = AbstractInterp4Command* (*)(void);
  // createCmdFunctionPtr pCreateCmd_Move;
  // void* pFun;

  // if (!pLibHnd_Move) {
  //   cerr << "!!! Brak biblioteki: " << lib_name << endl;
  //   return 1;
  // }

  // pFun = dlsym(pLibHnd_Move.get(), "CreateCmd");
  // if (!pFun) {
  //   cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
  //   return 1;
  // }
  // pCreateCmd_Move = reinterpret_cast<createCmdFunctionPtr>(pFun);
  // std::unique_ptr<AbstractInterp4Command> pCmd(pCreateCmd_Move());
  //****************************TEST MOVE***********************
  LibInterface move("libInterp4Move.dylib");
  using createCmdFunctionPtr = AbstractInterp4Command* (*)(void);
  createCmdFunctionPtr pCreateCmd_Move = move.getCreatedCmd();
  std::unique_ptr<AbstractInterp4Command> pCmd(pCreateCmd_Move());
  cout << endl;
  cout << move.getCmdName() << endl;
  cout << endl;
  pCmd->PrintSyntax();
  cout << endl;
  pCmd->PrintCmd();
  cout << endl;
  //****************************TEST Rotate***********************
  LibInterface rotate("libInterp4Rotate.dylib");
  createCmdFunctionPtr pCreateCmd_Rotate = rotate.getCreatedCmd();
  std::unique_ptr<AbstractInterp4Command> pCmd_rotate(pCreateCmd_Rotate());
  cout << endl;
  cout << pCmd_rotate->GetCmdName() << endl;
  cout << endl;
  pCmd_rotate->PrintSyntax();
  cout << endl;
  pCmd_rotate->PrintCmd();
  cout << endl;
  //****************************TEST Pause***********************
  LibInterface pause("libInterp4Pause.dylib");
  createCmdFunctionPtr pCreateCmd_Pause = pause.getCreatedCmd();
  std::unique_ptr<AbstractInterp4Command> pCmd_pause(pCreateCmd_Pause());
  cout << endl;
  cout << pCmd_pause->GetCmdName() << endl;
  cout << endl;
  pCmd_pause->PrintSyntax();
  cout << endl;
  pCmd_pause->PrintCmd();
  cout << endl;
  //****************************TEST Set***********************
  LibInterface set("libInterp4Set.dylib");
  createCmdFunctionPtr pCreateCmd_Set = set.getCreatedCmd();
  std::unique_ptr<AbstractInterp4Command> pCmd_set(pCreateCmd_Set());
  cout << endl;
  cout << pCmd_set->GetCmdName() << endl;
  cout << endl;
  pCmd_set->PrintSyntax();
  cout << endl;
  pCmd_set->PrintCmd();
  cout << endl;
}
