//
// Factory.cpp for  in /home/bourma_m/Projet/C++/cpp_bomberman/sources/Factory
// 
// Made by Mathieu Bourmaud
// Login   <bourma_m@epitech.net>
// 
// Started on  Mon May 25 11:56:05 2015 Mathieu Bourmaud
// Last update Mon May 25 19:03:42 2015 Mathieu Bourmaud
//

#include		"Factory.hpp"

Factory::Factory()
{
  // IEntity		*toto = new Bomb<int, int, int>();

  // toto->getType();
  // toto++;
  //  _ents[BOMB] = new Bomb<int, int, int>();
  // _ents[BOMB] = new Bomb<int, char, std::string>;
  // _ents[AI] = new AI;
  // _ents[MONSTER] = new Monster;
  // _ents[BOMBNUMBER] = new BombNumber;
  // _ents[RADIUS] = new Radius;
  // _ents[SPEED] = new Speed;
  // _ents[FLAME] = new Flame;
  // _ents[UBRKWALL] = new UbrkWall;
  // _ents[BRKWALL] = new BrkWall;
  // _ents[PLAYER] = new Player;
}

IEntity		*Factory::createEntity(eEntityType type)
{
  return (_ents[type]);
}
