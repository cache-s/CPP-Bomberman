//
// AI.hpp for  in /home/charie_p/rendu/cpp_bomberman/includes/Lua
//
// Made by Pierre Charie
// Login   <charie_p@epitech.net>
//
// Started on  Wed Jun 10 17:13:21 2015 Pierre Charie
// Last update Fri Jun 12 14:54:03 2015 Pierre Charie
//

#ifndef		AI_HPP
# define	AI_HPP

#include	<sstream>

# include       "Bomberman.hpp"
# include	"IEntity.hpp"

class		AInt
{
public:
  AInt(int width, int height, std::map<std::pair<int, int>, IEntity<glm::vec3> *> &playerMap, std::map<std::pair<int, int>, IEntity<glm::vec3> *> &gameMap, IEntity<glm::vec3> *player);
  ~AInt();
  void		move();
private:

  int		_width;
  int		_height;

  IEntity<glm::vec3>	*_player;
  std::map<std::pair<int, int>, IEntity<glm::vec3> *> &_playerMap;
  std::map<std::pair<int, int>, IEntity<glm::vec3> *> &_gameMap;

  std::string   mapMerge();
};

#endif
