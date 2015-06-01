
#include	"AssetsManager.hpp"

AssetsManager::AssetsManager()
{

}

AssetsManager::~AssetsManager()
{
}

void		AssetsManager::init()
{
  if (_model.load("./includes/LibBomberman/assets/marvin.fbx") == false)
    std::cout << "erreur loading model marvin" << std::endl;
  _models[PLAYER] = &_model;
}

gdl::Model*	AssetsManager::getModel(eEntityType type) const
{
  if (_models.find(type) != _models.end())
    return _models.find(type)->second;
  /* Throw exception */  
  return NULL;
}
