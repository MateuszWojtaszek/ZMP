#pragma once
#include <map>
#include <memory>
#include "AbstractScene.hh"
#include "AccessControl.hh"
class Scene : public AbstractScene, public AccessControl {
  std::map<std::string, std::shared_ptr<AbstractMobileObj>> _ObjectsMap;

 public:
  AbstractMobileObj* FindMobileObj(const char* sName) override;
  void AddMobileObj(AbstractMobileObj* pMobObj) override;
};