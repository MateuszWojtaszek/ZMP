#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include "AbstractInterp4Command.hh"
// instead of using namespace std
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int main()
{
#if defined(__APPLE__)
  const char *lib_name = "libInterp4Move.dylib";
#elif defined(__linux__)
  const char *lib_name = "libInterp4Move.so";
#else
#error "Unsupported platform"
#endif
  auto libHandlerDeleter = [](void *libPtr)
  {
    if (libPtr)
    {
      dlclose(libPtr);
    }
  };

  std::unique_ptr<void, decltype(libHandlerDeleter)>
      pLibHnd_Move(dlopen(lib_name, RTLD_LAZY), libHandlerDeleter);

  using createCmdFunctionPtr = AbstractInterp4Command *(*)(void);
  createCmdFunctionPtr pCreateCmd_Move;
  void *pFun;

  if (!pLibHnd_Move)
  {
    cerr << "!!! Brak biblioteki: " << lib_name << endl;
    return 1;
  }

  pFun = dlsym(pLibHnd_Move.get(), "CreateCmd");
  if (!pFun)
  {
    cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
    return 1;
  }
  pCreateCmd_Move = reinterpret_cast<createCmdFunctionPtr>(pFun);

  std::unique_ptr<AbstractInterp4Command> pCmd(pCreateCmd_Move());
  cout << endl;
  cout << pCmd->GetCmdName() << endl;
  cout << endl;
  pCmd->PrintSyntax();
  cout << endl;
  pCmd->PrintCmd();
  cout << endl;
}
