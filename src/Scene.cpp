#include "Scene.hpp"

AbstractMobileObj* Scene::FindMobileObj(const char* sName) {
  auto it = _ObjectsMap.find(sName);
  if (it != _ObjectsMap.end()) {
    return it->second.get();
  }
  return nullptr;
}

void Scene::AddMobileObj(AbstractMobileObj* pMobObj) {
  std::shared_ptr<AbstractMobileObj> ptr(pMobObj);
  _ObjectsMap[ptr->GetName()] = ptr;
}