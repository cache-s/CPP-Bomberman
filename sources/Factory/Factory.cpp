//
// Factory.cpp for  in /home/bourma_m/Projet/C++/cpp_bomberman/sources/Factory
// 
// Made by Mathieu Bourmaud
// Login   <bourma_m@epitech.net>
// 
// Started on  Mon May 25 11:56:05 2015 Mathieu Bourmaud
// Last update Wed May 27 10:41:33 2015 Mathieu Bourmaud
//

#include		"Factory.hpp"

template <class T>
Factory<T>::Factory()
{
  _ents[BOMB] = new Bomb<glm::vec3>;
  _ents[ARTINT] = new AI<glm::vec3>;
  _ents[MONSTER] = new Monster<glm::vec3>;
  _ents[BOMBNUMBER] = new BombNumber<glm::vec3>;
  _ents[RADIUS] = new Radius<glm::vec3>;
  _ents[SPEED] = new Speed<glm::vec3>;
  _ents[FLAME] = new Flame<glm::vec3>;
  _ents[UBRKWALL] = new UbrkWall<glm::vec3>;
  _ents[BRKWALL] = new BrkWall<glm::vec3>;
  _ents[PLAYER] = new Player<glm::vec3>;
}

template <class T>
IEntity<T>	*Factory<T>::createEntity(eEntityType type)
{
  return (_ents[type]->clone());
}
