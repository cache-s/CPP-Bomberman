//
// Factory.cpp for  in /home/bourma_m/Projet/C++/cpp_bomberman/sources/Factory
// 
// Made by Mathieu Bourmaud
// Login   <bourma_m@epitech.net>
// 
// Started on  Mon May 25 11:56:05 2015 Mathieu Bourmaud
// Last update Wed May 27 11:42:39 2015 Mathieu Bourmaud
//

#include		"Factory.hpp"

template <class T>
Factory<T>::Factory()
{
  _ents[BOMB] = new Bomb<T>;
  _ents[ARTINT] = new AI<T>;
  _ents[MONSTER] = new Monster<T>;
  _ents[BOMBNUMBER] = new BombNumber<T>;
  _ents[RADIUS] = new Radius<T>;
  _ents[SPEED] = new Speed<T>;
  _ents[FLAME] = new Flame<T>;
  _ents[UBRKWALL] = new UbrkWall<T>;
  _ents[BRKWALL] = new BrkWall<T>;
  _ents[PLAYER] = new Player<T>;
}

template <class T>
IEntity<T>	*Factory<T>::createEntity(eEntityType type)
{
  return (_ents[type]->clone());
}
