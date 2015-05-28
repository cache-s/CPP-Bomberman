//
// Lua.hpp for  in /home/charie_p/rendu/cpp_bomberman/includes/Lua
//
// Made by Pierre Charie
// Login   <charie_p@epitech.net>
//
// Started on  Wed May 27 11:40:48 2015 Pierre Charie
// Last update Thu May 28 14:06:16 2015 Pierre Charie
//

#ifndef		LUA_HPP_
#define		LUA_HPP_


# include	"Bomberman.hpp"
# include	"IEntity.hpp"

class Lua
{
public:
  Lua();
  ~Lua();
  std::string							luaMapLoad(std::string fileLoad, std::string functionName, int width, int height);
  std::map<std::make_pair<int x, int y>, IEntity entity>	mapGenerate(int width, int height);
private:
};

#endif
