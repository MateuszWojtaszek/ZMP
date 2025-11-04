#pragma once
#include <dlfcn.h>
#include <string>
#include "AbstractInterp4Command.hh"

class LibInterface {
  using createCmdFunctionPtr = AbstractInterp4Command* (*)(void);
  using createCmdNamePtr = const char* (*)();

  void* const _LibHandler;
  std::string _CmdName;
  createCmdFunctionPtr _pCreateCmd;

 public:
  LibInterface(const char* plugin);
  ~LibInterface();
  std::string getCmdName() const { return _CmdName; }
  createCmdFunctionPtr getCreatedCmd() const { return _pCreateCmd; }
};