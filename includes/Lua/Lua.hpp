//
// Lua.hpp for  in /home/charie_p/rendu/cpp_bomberman/includes/Lua
//
// Made by Pierre Charie
// Login   <charie_p@epitech.net>
//
// Started on  Wed May 27 11:40:48 2015 Pierre Charie
// Last update Thu May 28 13:52:14 2015 Pierre Charie
//

#include "Bomberman.hpp"

class Lua
{
public:
  Lua();
  ~Lua();
  std::string  luaMapLoad(std::string fileLoad, std::string functionName, int width, int height);
private:
};
