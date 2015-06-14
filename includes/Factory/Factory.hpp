//
// Factory.hpp for  in /home/bourma_m/Projet/C++/cpp_bomberman
//
// Made by Mathieu Bourmaud
// Login   <bourma_m@epitech.net>
//
// Started on  Mon May 25 11:56:52 2015 Mathieu Bourmaud
// Last update Sun Jun 14 21:11:29 2015 Jordan Chazottes
//

#ifndef			_FACTORY_HPP_
# define		_FACTORY_HPP_

# include		"Bomb.hpp"
# include		"AI.hpp"
# include		"Monster.hpp"
# include		"BombNumber.hpp"
# include		"Radius.hpp"
# include		"Speed.hpp"
# include		"Floor.hpp"
# include		"MapWall.hpp"
# include		"Flame.hpp"
# include		"UbrkWall.hpp"
# include		"BrkWall.hpp"
# include		"Player.hpp"

template <typename T>
class			Factory
{
public:
  Factory();
  ~Factory();
  IEntity<T>	*createEntity(eEntityType type, int x, int y);
private:
  std::map<eEntityType, IEntity<T> *>	_ents;
};

template <typename T>
Factory<T>::Factory()
{
  _ents[BOMB] = new Bomb<T>;
  _ents[MAPWALL] = new MapWall<T>;
  _ents[FLOOR] = new Floor<T>;
  _ents[ARTINT] = new AI<T>;
  _ents[MONSTER] = new Monster<T>;
  _ents[BBOMBNUMBER] = new BombNumber<T>;
  _ents[BRADIUS] = new Radius<T>;
  _ents[BSPEED] = new Speed<T>;
  _ents[FLAME] = new Flame<T>;
  _ents[UBRKWALL] = new UbrkWall<T>;
  _ents[BRKWALL] = new BrkWall<T>;
  _ents[PLAYER] = new Player<T>;
}

template <typename T>
Factory<T>::~Factory()
{
}

template <typename T>
IEntity<T>	*Factory<T>::createEntity(eEntityType type, int x, int y)
{
  return (_ents[type]->clone(x, y));
}

#endif
