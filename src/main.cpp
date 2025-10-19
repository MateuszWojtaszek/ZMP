#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include "AbstractInterp4Command.hh"

using namespace std;

int main()
{
  // Gdzieś na początku pliku, gdzie definiujesz nazwę biblioteki
#if defined(__APPLE__)
  const char *lib_name = "libInterp4Move.dylib";
#elif defined(__linux__)
  const char *lib_name = "libInterp4Move.so";
#else
#error "Unsupported platform"
#endif

  void *pLibHnd_Move = dlopen(lib_name, RTLD_LAZY);
  AbstractInterp4Command *(*pCreateCmd_Move)(void);
  void *pFun;

  if (!pLibHnd_Move)
  {
    cerr << "!!! Brak biblioteki: " << lib_name << endl;
    return 1;
  }

  pFun = dlsym(pLibHnd_Move, "CreateCmd");
  if (!pFun)
  {
    cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
    return 1;
  }
  pCreateCmd_Move = reinterpret_cast<AbstractInterp4Command *(*)(void)>(pFun);

  AbstractInterp4Command *pCmd = pCreateCmd_Move();

  cout << endl;
  cout << pCmd->GetCmdName() << endl;
  cout << endl;
  pCmd->PrintSyntax();
  cout << endl;
  pCmd->PrintCmd();
  cout << endl;

  delete pCmd;

  dlclose(pLibHnd_Move);
}
