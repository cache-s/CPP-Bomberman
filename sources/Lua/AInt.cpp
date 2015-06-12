//
// AInt.cpp for  in /home/charie_p/rendu/cpp_bomberman/sources/Lua
//
// Made by Pierre Charie
// Login   <charie_p@epitech.net>
//
// Started on  Fri Jun 12 11:37:56 2015 Pierre Charie
// Last update Fri Jun 12 12:28:09 2015 Pierre Charie
//


extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}


#include "AInt.hpp"
#include "IEntity.hpp"


AInt::AInt(int width, int height)
{
  _width = width;
  _height = height;
}

AInt::~AInt()
{

}

std::string	AInt::mapMerge(std::map<std::pair<int, int>, IEntity<glm::vec3> *> playerMap, std::map<std::pair<int, int>, IEntity<glm::vec3> *> gameMap)
{
  int	tmp;
  std::string result;

  int x = 0, y = 0;

  while (y < _height)
    {
      while (x < _width)
	{
	  if (gameMap[std::make_pair(x, y)] == NULL)
	    if (playerMap[std::make_pair(x, y)] == NULL)
	      tmp = 0;
	    else
	      tmp += playerMap[std::make_pair(x, y)]->getType();
	  else
	    tmp += gameMap[std::make_pair(x, y)]->getType();

	  std::stringstream ss;
	  ss << tmp;
	  result += ss.str();
	  x++;
	}
      y++;
    }

  std::size_t found = result.find("32");
  int i = 0;


  while (found != std::string::npos)
    {
      result[found - 1] = '3';
      result[found - 2] = '3';

      result[found - 3] = '3';
      result[found - 4] = '3';

      result[found - 5] = '3';
      result[found - 6] = '3';

      result[found - _width] = '3';
      result[found - _width + 1] = '3';

      result[found - _width * 2] = '3';
      result[found - _width * 2 + 1] = '3';

      result[found - _width * 3] = '3';
      result[found - _width * 3 + 1] = '3';

      result[found + 2] = '3';
      result[found + 3] = '3';
      result[found + 4] = '3';
      result[found + 5] = '3';
      result[found + 6] = '3';
      result[found + 7] = '3';

      result[found + _width] = '3';
      result[found + _width + 1] = '3';
      result[found + _width * 2] = '3';
      result[found + _width * 2 + 1] = '3';
      result[found + _width * 3] = '3';
      result[found + _width * 3 + 1] = '3';
      i++;
      found = result.find("32", i);
    }

  return result;
} // DZ = 33, BMB = 32

void		AInt::move(std::string, int width, int height, int selfX, int selfY)
{
  lua_State*            L = luaL_newstate();
  int			action;


  luaL_openlibs(L);
  if (luaL_loadfile(L, "./sources/Scripts/AI/aggressiveAI.lua") || lua_pcall(L, 0, 0, 0))
    throw std::runtime_error("Couldn't load the AI");
  lua_getglobal(L, "act");
  if(!lua_isfunction(L,-1))
    {
      lua_pop(L,1);
      std::string error;
      error = "Error, function doesn't exist in";
      throw std::runtime_error(error);
    }
  lua_pushstring(L, map.c_str());
  lua_pushinteger(L, width);
  lua_pushinteger(L, height);
  lua_pushinteger(L, selfX);
  lua_pushinteger(L, selfY);

  if (lua_pcall(L, 5, 1, 0) != 0)
    {
      std::string error;
      error = "Error running LUA function";
      throw std::runtime_error(error);
    }
  action = lua_tointeger(L, -1);
  lua_pop(L, 1);
  (void)action;
}
