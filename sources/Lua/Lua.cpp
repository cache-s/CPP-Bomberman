//
// Lua.cpp for  in /home/charie_p/rendu/cpp_bomberman/sources/Lua
//
// Made by Pierre Charie
// Login   <charie_p@epitech.net>

//
// Started on  Wed May 27 11:31:12 2015 Pierre Charie
// Last update Mon Jun  8 11:40:47 2015 Pierre Charie
//

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include "MapGen.hpp"
#include "IEntity.hpp"

MapGen::MapGen()
{
}

MapGen::~MapGen()
{
}




std::string MapGen::luaMapLoad(std::string fileLoad, std::string functionName)
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
  lua_pushinteger(L, _width);
  lua_pushinteger(L, _height);
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


std::map<std::pair<int, int>, IEntity<glm::vec3> *> MapGen::mapGenerate(int width, int height)
{
  std::string   mapLua;
  int           i = 0;
  int           x, y = 0;
  std::map<std::pair<int, int>, IEntity<glm::vec3> *> gameMap;

  _width = width;
  _height = height;

  mapLua = luaMapLoad("./sources/Scripts/map/maprandom.lua", "serializeMap");

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
	item = _fac.createEntity(static_cast<eEntityType>(intType), x, y);
      gameMap[std::pair<int, int>(x, y)] = item;
     //  std::cout << item->getType() << std::endl;
     //      std::cout << gameMap[std::make_pair(x, y)] << std::endl;
      i++;
      x++;
      if (x == _width)
        {
          x = 0;
          y++;
        }
    }
    _map = gameMap;
    return gameMap;
}

std::map<std::pair<int, int>, IEntity<glm::vec3> *>	MapGen::playerMapGenerate(int playerNbr)
{
  std::map<std::pair<int, int>, IEntity<glm::vec3> *>	playerMap;
  // int							x = 0, y = 0;

  if (playerNbr > (_width * _height / 9))
    throw std::range_error("to many player for this size of map");

  return _map; //a retirer
}

void                                                     MapGen::spawnPlayer(int posX, int posY)
{
  _map[std::make_pair(posX, posY)] = _fac.createEntity(PLAYER , posX, posY);

  // if (_map[std::make_pair(posX, posY)])
  //     _map[std::make_pair(posX, posY)] =
}
