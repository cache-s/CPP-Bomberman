
#include	"AssetsManager.hpp"

AssetsManager::AssetsManager()
{

}

AssetsManager::~AssetsManager()
{
}

void		AssetsManager::init()
{
  _texture.reserve(10);

  if (_model.load("./includes/LibBomberman/assets/marvin.fbx") == false)
    std::cout << "erreur loading model marvin" << std::endl;
  _models[PLAYER] = &_model;  
  
  if (_texture[0].load("./assets/hardened_clay_stained_cyan.tga") == false)
    std::cerr << "error loading grass" << std::endl;
  _textures[FLOOR] = &_texture[0];
  
  if (_texture[1].load("./assets/ice.tga") == false)
    std::cerr << "error loading tnt" << std::endl;
  _textures[BOMB] = &_texture[1];
  
  if (_texture[2].load("./assets/planksbirch.tga") == false)
    std::cerr << "error loading grass" << std::endl;
  _textures[BRKWALL] = &_texture[2];
  
  if (_texture[3].load("./assets/test.tga") == false)
    std::cerr << "error loading grass" << std::endl;  
  _textures[UBRKWALL] = &_texture[3];
  
  if (_texture[4].load("./assets/lava.tga") == false)
    std::cerr << "error loading fdp" << std::endl;
  _textures[FLAME] = &_texture[4];
}

gdl::Model*	AssetsManager::getModel(eEntityType type) const
{
  if (_models.find(type) != _models.end())
    return _models.find(type)->second;
  /* Throw exception */  
  return NULL;
}
gdl::Texture*	AssetsManager::getTexture(eEntityType type) const
{
  if (_textures.find(type) != _textures.end())
    return _textures.find(type)->second;
  /* Throw exception */  
  return NULL;
}
