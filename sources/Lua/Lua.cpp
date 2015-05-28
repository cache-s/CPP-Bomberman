//
// Lua.cpp for  in /home/charie_p/rendu/cpp_bomberman/sources/Lua
//
// Made by Pierre Charie
// Login   <charie_p@epitech.net>
//
// Started on  Wed May 27 11:31:12 2015 Pierre Charie
// Last update Wed May 27 16:49:56 2015 Pierre Charie
//

#include "Lua.hpp"

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

std::string Lua::luaMapLoad(std::string fileLoad, std::string functionName, int width, int height)
{
  lua_State*            L = luaL_newstate();
  std::string           map;

  luaL_openlibs(L);
  if (luaL_loadfile(L, fileLoad) || lua_pcall(L, 0, 0, 0))
    throw std::runtime_error(lua_tostring(L, -1));
  lua_getglobal(L, functionName);
  if(!lua_isfunction(L,-1))
    {
      lua_pop(L,1);
      std::string error;
      error = "Error, function" + functionName + "doesn't exist in" + fileLoad;
      throw std::runtime_error(error);
    }
  lua_pushinteger(L, width);
  lua_pushinteger(L, height);
  if (lua_pcall(L, 2, 1, 0) != 0)
    {
      std::string error;
      error = "Error running function : " + functionName + lua_tostring(L, -1);
      throw std::runtime_error(error);
    }
  map = lua_tostring(L, -1);
  lua_pop(L, 1);
  std::cout << "reçu du lua : " << map << std::endl;
  return map;
}


std::map<std::make_pair(int x, int y), IEntity entity> Lua::mapGenerate(int width, int height)
{
  std::string   mapLua;
  int           i = 0;
  int           x, y = 0;
  std::map<std::make_pair(int x, int y), IEntity entity> gameMap;

  //mapLua = generateMap(width, height); TODO linker avec la fonction LUA

  while (mapLua[i])
    {
      switch (mapLua[i])
        {
        case 0: //sol
          break;
        case 1: //mur destructible
          //      gameMap[x][y] = ;
          break;
        case 2: //mur indestructible
          //gameMap[x][y] = ;
          break;
        case 3: //bord de map
          //gameMap[x][y] = ;
          break;
        }
      x++;
      if (x == width)
        {
          x = 0;
          height++;
        }
    }
  return gameMap();
}