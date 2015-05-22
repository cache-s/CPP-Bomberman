
#include	"AssetsManager.hpp"

AssetsManager::AssetsManager()
{
  gdl::Model *model = NULL;

  if (model->load("./assets/marvin.fbx") == false)
    {
      /* Throw exception */        
    }
  _models[PLAYER] = model;
}

AssetsManager::~AssetsManager()
{
}

gdl::Model*	AssetsManager::getModel(eEntityType type)
{
  if (_models.find(type) != _models.end())
    return _models.find(type)->second;
  /* Throw exception */  
  return NULL;
}
