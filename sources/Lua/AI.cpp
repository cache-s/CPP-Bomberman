//
// AI.cpp for  in /home/charie_p/rendu/cpp_bomberman/sources/Lua
//
// Made by Pierre Charie
// Login   <charie_p@epitech.net>
//
// Started on  Wed Jun 10 17:32:16 2015 Pierre Charie
// Last update Wed Jun 10 18:16:56 2015 Pierre Charie
//

#include "AI.hpp"

Ai::AI(int width, int height)
{
  _width = width;
  _height = height;
}

Ai::~AI()
{

}

std::string	AI::mapMerge(std::map<std::pair<int, int>, IEntity<glm::vec3> *> playerMap, std::map<std::pair<int, int>, IEntity<glm::vec3> *> gameMap)
{
  std::string result;

  int x = 0, y = 0;

  while (y < height)
    {
      while (x < width)
	{
	  if (gameMap[std::make_pair(x, y)] == NULL)
	    if (playerMap[std::make_pair(x, y)] == NULL)
	      result += 0;
	    else
	      result += playerMap[std::make_pair(x, y)]->getType();
	  else
	    result += gameMap[std::make_pair(x, y)]->getType();
	  x++;
	}
      y++;
    }
}

void		AI::move(std::string map, int width, int height, int selfX, int selfY)
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
  lua_pushstring(L, map);
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
}
