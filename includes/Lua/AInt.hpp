//
// AI.hpp for  in /home/charie_p/rendu/cpp_bomberman/includes/Lua
//
// Made by Pierre Charie
// Login   <charie_p@epitech.net>
//
// Started on  Wed Jun 10 17:13:21 2015 Pierre Charie
// Last update Sun Jun 14 19:25:15 2015 Pierre Charie
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
# include	"EventManager.hpp"

template <typename T>
class           EventManager;

template <typename T>
class		AInt
{
public:
  AInt(int width, int height, std::map<std::pair<int, int>, IEntity<T> *> &playerMap, std::map<std::pair<int, int>, IEntity<T> *> &gameMap, IEntity<T> *player, ISafeQueue<std::pair<typename EventManager<T>::eEvent, IEntity<T> *> > &eventQueue, ICondVar &eventCondVar, ICondVar &AICondVar);
  ~AInt();
  void		move();
private:

  std::string	_path;
  std::string	_func;

  int		_width;
  int		_height;

  IEntity<T>	*_player;
  std::map<std::pair<int, int>, IEntity<T> *> &_playerMap;
  std::map<std::pair<int, int>, IEntity<T> *> &_gameMap;
  ISafeQueue<std::pair<typename EventManager<T>::eEvent, IEntity<T> *> > &_eventQueue;
  ICondVar      &_eventCondVar;
  ICondVar      &_AICondVar;

  std::string   mapMerge();
  void		checkMapPos(std::string &map, int pos);
};

#include "AInt.tpp"

#endif
