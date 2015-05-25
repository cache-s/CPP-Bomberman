//
// Factory.hpp for  in /home/bourma_m/Projet/C++/cpp_bomberman
// 
// Made by Mathieu Bourmaud
// Login   <bourma_m@epitech.net>
// 
// Started on  Mon May 25 11:56:52 2015 Mathieu Bourmaud
// Last update Mon May 25 12:27:21 2015 Mathieu Bourmaud
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

class			Factory
{
public:
  Factory();
  ~Factory();
  IEntity		*createEntity(eEntityType type);
private:
  std::map<eEntityType, IEntity *>	_ents;
};

#endif
