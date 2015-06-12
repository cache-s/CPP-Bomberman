//
// AI.hpp for  in /home/charie_p/rendu/cpp_bomberman/includes/Lua
//
// Made by Pierre Charie
// Login   <charie_p@epitech.net>
//
// Started on  Wed Jun 10 17:13:21 2015 Pierre Charie
// Last update Fri Jun 12 17:02:30 2015 Pierre Charie
//

#ifndef		AI_HPP
# define	AI_HPP

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}


#include	<sstream>

# include       "Bomberman.hpp"
# include	"IEntity.hpp"

template <typename T>
class		AInt
{
public:
  AInt(int width, int height, std::map<std::pair<int, int>, IEntity<T> *> &playerMap, std::map<std::pair<int, int>, IEntity<T> *> &gameMap, IEntity<T> *player);
  ~AInt();
  void		move();
private:

  int		_width;
  int		_height;

  IEntity<T>	*_player;
  std::map<std::pair<int, int>, IEntity<T> *> &_playerMap;
  std::map<std::pair<int, int>, IEntity<T> *> &_gameMap;

  std::string   mapMerge();
};

#include "AInt.tpp"

#endif
