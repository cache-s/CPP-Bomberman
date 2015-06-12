//
// AI.hpp for  in /home/charie_p/rendu/cpp_bomberman/includes/Lua
//
// Made by Pierre Charie
// Login   <charie_p@epitech.net>
//
// Started on  Wed Jun 10 17:13:21 2015 Pierre Charie
// Last update Fri Jun 12 12:28:38 2015 Pierre Charie
//

#ifndef		AI_HPP
# define	AI_HPP

#include	<sstream>

# include       "Bomberman.hpp"
# include	"IEntity.hpp"

class		AInt
{
public:
  AInt(int, int);
  ~AInt();
  void		move(std::string, int, int, int, int);
private:

  int		_width;
  int		_height;

  std::string   mapMerge(std::map<std::pair<int, int>, IEntity<glm::vec3> *> playerMap, std::map<std::pair<int, int>, IEntity<glm::vec3> *> gameMap);
};

#endif
