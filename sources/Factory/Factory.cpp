//
// Factory.cpp for  in /home/bourma_m/Projet/C++/cpp_bomberman/sources/Factory
// 
// Made by Mathieu Bourmaud
// Login   <bourma_m@epitech.net>
// 
// Started on  Mon May 25 11:56:05 2015 Mathieu Bourmaud
// Last update Tue May 26 11:47:47 2015 Mathieu Bourmaud
//

#include		"Factory.hpp"

template <class T>
Factory<T>::Factory()
{
  // IEntity<int>	*toto;
  
  // (void)toto;
  // toto->getType();
  // toto++;
  _ents[BOMB] = new Bomb<glm::vec3>;
  // _ents[ARTINT] = new AI<glm::vec3>;
  // _ents[MONSTER] = new Monster;
  // _ents[BOMBNUMBER] = new BombNumber;
  // _ents[RADIUS] = new Radius;
  // _ents[SPEED] = new Speed;
  // _ents[FLAME] = new Flame;
  // _ents[UBRKWALL] = new UbrkWall;
  // _ents[BRKWALL] = new BrkWall;
  // _ents[PLAYER] = new Player;
}

template <class T>
IEntity<T>	*Factory<T>::createEntity(eEntityType type)
{
  return (_ents[type]);
}
