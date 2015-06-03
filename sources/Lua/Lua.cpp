//
// Lua.cpp for  in /home/charie_p/rendu/cpp_bomberman/sources/Lua
//
// Made by Pierre Charie
// Login   <charie_p@epitech.net>

//
// Started on  Wed May 27 11:31:12 2015 Pierre Charie
// Last update Wed Jun  3 15:26:52 2015 Pierre Charie
//

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include "Lua.hpp"
#include "IEntity.hpp"

Lua::Lua()
{
}

Lua::~Lua()
{
}




std::string Lua::luaMapLoad(std::string fileLoad, std::string functionName, int width, int height)
{
  lua_State*            L = luaL_newstate();
  std::string           map;

  luaL_openlibs(L);
  if (luaL_loadfile(L, fileLoad.c_str()) || lua_pcall(L, 0, 0, 0))
    throw std::runtime_error(lua_tostring(L, -1));
  lua_getglobal(L, functionName.c_str());
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
  return map;
}


std::map<std::pair<int, int>, IEntity<glm::vec3> *> Lua::mapGenerate(int width, int height)
{
  std::string   mapLua;
  int           i = 0;
  int           x, y = 0;
  std::map<std::pair<int, int>, IEntity<glm::vec3> *> gameMap;
  Factory	<glm::vec3>fac;

  mapLua = luaMapLoad("./sources/Scripts/map/maprandom.lua", "serializeMap", width, height);

    while (mapLua[i])
    {
      std::stringstream ssType;
      IEntity<glm::vec3> *item;
      int intType;

      ssType << mapLua[i];
      ssType >> intType;
      if (intType == 0)
	item = NULL;
      else
	item = fac.createEntity(static_cast<eEntityType>(intType), x, y);
      item++;
      gameMap[std::pair<int, int>(x, y)] = item;
      //      std::cout << gameMap[std::make_pair(x, y)] << std::endl;
      i++;
      x++;
      if (x == width)
        {
          x = 0;
          y++;
        }
    }
  return gameMap;
}
