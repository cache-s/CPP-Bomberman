//
// Lua.hpp for  in /home/charie_p/rendu/cpp_bomberman/includes/Lua
//
// Made by Pierre Charie
// Login   <charie_p@epitech.net>
//
// Started on  Wed May 27 11:40:48 2015 Pierre Charie
// Last update Fri May 29 11:36:13 2015 Pierre Charie
//

#ifndef		LUA_HPP_
#define		LUA_HPP_


# include	"Bomberman.hpp"
# include	"AEntity.hpp"

class Lua
{
public:
  Lua();
  ~Lua();
  std::string							luaMapLoad(std::string fileLoad, std::string functionName, int width, int height);
  std::map<std::pair<int, int>, IEntity<glm::vec3> *>		mapGenerate(int width, int height);
private:
};

#endif
