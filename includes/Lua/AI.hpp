//
// AI.hpp for  in /home/charie_p/rendu/cpp_bomberman/includes/Lua
//
// Made by Pierre Charie
// Login   <charie_p@epitech.net>
//
// Started on  Wed Jun 10 17:13:21 2015 Pierre Charie
// Last update Wed Jun 10 18:01:14 2015 Pierre Charie
//

#ifndef		AI_HPP
# define	AI_HPP

# include       "Bomberman.hpp"

class		AI
{
public:
  AI();
  ~AI();
  void		move();
private:

  std::string   mapMerge(std::map<std::pair<int, int>, IEntity<glm::vec3> *> playerMap, std::map<std::pair<int, int>, IEntity<glm::vec3> *> gameMap);
};

#endif
