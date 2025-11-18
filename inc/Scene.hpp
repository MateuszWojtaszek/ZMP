#pragma once
#include <map>
#include <memory>
#include "AbstractScene.hh"

class Scene : public AbstractScene {
  std::map<std::string, std::shared_ptr<AbstractMobileObj>> _ObjectsMap;

 public:
  AbstractMobileObj* FindMobileObj(const char* sName) override;
  void AddMobileObj(AbstractMobileObj* pMobObj) override;
};