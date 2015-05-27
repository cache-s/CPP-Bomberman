//
// Factory.hpp for  in /home/bourma_m/Projet/C++/cpp_bomberman
// 
// Made by Mathieu Bourmaud
// Login   <bourma_m@epitech.net>
// 
// Started on  Mon May 25 11:56:52 2015 Mathieu Bourmaud
// Last update Wed May 27 17:48:49 2015 Mathieu Bourmaud
//

#ifndef			_FACTORY_HPP_
# define		_FACTORY_HPP_

# include		"Bomb.hpp"
# include		"AI.hpp"
# include		"Monster.hpp"
# include		"BombNumber.hpp"
# include		"Radius.hpp"
# include		"Speed.hpp"
# include		"Flame.hpp"
# include		"UbrkWall.hpp"
# include		"BrkWall.hpp"
# include		"Player.hpp"

template <class T>
class			Factory
{
public:
  Factory();
  ~Factory();
  IEntity<T>		*createEntity(eEntityType type);
private:
  std::map<eEntityType, IEntity<T> *>	_ents;
};

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
Factory<T>::~Factory()
{
}

template <class T>
IEntity<T>	*Factory<T>::createEntity(eEntityType type)
{
  return (_ents[type]->clone());
}

#endif
