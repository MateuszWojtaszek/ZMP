#pragma once
#include <dlfcn.h>
#include <string>
#include "AbstractInterp4Command.hh"

class LibInterface {
  void* const _LibHandler;
  std::string _CmdName;
  using createCmdFunctionPtr = AbstractInterp4Command* (*)(void);
  createCmdFunctionPtr _pCreateCmd;
  using createCmdNamePtr = const char* (*)();

 public:
  LibInterface(const char* plugin);
  ~LibInterface();
  std::string getCmdName() const { return _CmdName; }
  createCmdFunctionPtr getCreatedCmd() const { return _pCreateCmd; }
};