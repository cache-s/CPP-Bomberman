//
// Lua.cpp for  in /home/charie_p/rendu/cpp_bomberman/sources/Lua
//
// Made by Pierre Charie
// Login   <charie_p@epitech.net>

//
// Started on  Wed May 27 11:31:12 2015 Pierre Charie
// Last update Mon Jun  8 18:58:09 2015 Mathieu Bourmaud
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
int							random = 0;
  if (playerNbr > (_width * _height / 15))
    throw std::range_error("to many player for this size of map") ;

  srand (time(NULL));

  random = rand() % 4 + 1;
  switch (playerNbr)
    {
    case 2:
      if (random == 1)
	{
	  spawnPlayer(1,1);
	  spawnPlayer(_width - 1, _height - 1);
	}
      if (random == 2)
	{
	  spawnPlayer(_width - 1, 1);
	  spawnPlayer(1, _height - 1);
	}
      if (random == 3)
	{
	  spawnPlayer(1, _height - 1);
	  spawnPlayer(_width - 1, 1);
	}
      if (random == 4)
	{
	  spawnPlayer(_width - 1, _height - 1);
	  spawnPlayer(1, 1);
	}

    case 3:
      if (random == 1)
	{
	  spawnPlayer(1,1);
	  spawnPlayer(_width - 1, _height - 1);
	}
      if (random == 2)
	{
	  spawnPlayer(_width - 1, 1);
	  spawnPlayer(1, _height - 1);
	}
      if (random == 3)
	{
	  spawnPlayer(1, _height - 1);
	  spawnPlayer(_width - 1, 1);
	}
      if (random == 4)
	{
	  spawnPlayer(_width - 1, _height - 1);
	  spawnPlayer(1, 1);
	}
      if (random == 1)
	spawnPlayer(1, _height - 1);
      if (random == 2)
	spawnPlayer(1, 1);
      if (random == 3)
	spawnPlayer(_width - 1, _height - 1);
      if (random == 4)
	spawnPlayer(_width - 1, 1);

    case 4:
      spawnPlayer(1, _height - 1);
      spawnPlayer(_width - 1, 1);
      spawnPlayer(1, 1);
      spawnPlayer(_width - 1, _height - 1);

    case 5:
      spawnPlayer(1, _height - 1);
      spawnPlayer(_width - 1, 1);
      spawnPlayer(1, 1);
      spawnPlayer(_width - 1, _height - 1);
      spawnPlayer(_width / 2, _height / 2);
    default :
      spawnPlayer(1, _height - 1);
      spawnPlayer(_width - 1, 1);
      spawnPlayer(1, 1);
      spawnPlayer(_width - 1, _height - 1);
      spawnPlayer(_width / 2, _height / 2);
      spawnRandomPlayer(playerNbr - 5);
    }

  return _pMap;
}

void                                                     MapGen::spawnPlayer(int posX, int posY)
{

  static int playerNb = 0;

  _pMap[std::make_pair(posX, posY)] = _fac.createEntity(PLAYER , posX, posY);

  if (playerNb == 0)
    _pMap[std::make_pair(-1, -1)] = _pMap[std::make_pair(posX, posY)];
  if (playerNb == 1)
    _pMap[std::make_pair(-2, -2)] = _pMap[std::make_pair(posX, posY)];

  if (posX > 0 && posY > 0 && _map[std::make_pair(posX - 1, posY - 1)] != NULL)
    if (_map[std::make_pair(posX - 1, posY - 1)]->getType() != MAPWALL)
      _map[std::make_pair(posX - 1, posY - 1)] = NULL;
  if (posX > 0 && posY > 0 && _map[std::make_pair(posX, posY - 1)] != NULL)
    if (_map[std::make_pair(posX, posY - 1)]->getType() != MAPWALL)
      _map[std::make_pair(posX, posY - 1)] = NULL;
  if (posX > 0 && posY > 0 && _map[std::make_pair(posX + 1, posY - 1)])
    if (_map[std::make_pair(posX + 1, posY - 1)]->getType() != MAPWALL)
      _map[std::make_pair(posX + 1, posY - 1)] = NULL;
  
  if (posX > 0 && posY > 0 && _map[std::make_pair(posX - 1, posY)])
    if (_map[std::make_pair(posX - 1, posY)]->getType() != MAPWALL)
      _map[std::make_pair(posX - 1, posY)] = NULL;
  if (posX > 0 && posY > 0 && _map[std::make_pair(posX + 1, posY)])
    if (_map[std::make_pair(posX + 1, posY)]->getType() != MAPWALL)
      _map[std::make_pair(posX + 1, posY)] = NULL;
  
  if (posX > 0 && posY > 0 && _map[std::make_pair(posX - 1, posY + 1)])
    if (_map[std::make_pair(posX - 1, posY + 1)]->getType() != MAPWALL)
      _map[std::make_pair(posX - 1, posY + 1)] = NULL;
  if (posX > 0 && posY > 0 && _map[std::make_pair(posX, posY + 1)])
    if (_map[std::make_pair(posX, posY + 1)]->getType() != MAPWALL)
      _map[std::make_pair(posX, posY + 1)] = NULL;
  if (posX > 0 && posY > 0 && _map[std::make_pair(posX + 1, posY + 1)])
    if (_map[std::make_pair(posX + 1, posY + 1)]->getType() != MAPWALL)
      _map[std::make_pair(posX + 1, posY + 1)] = NULL;
  
  playerNb++;
}

void                                                     MapGen::spawnRandomPlayer(int playerNbr)
{
  bool	good;
  int	posX, posY;


  while (playerNbr > 0)
    {
      good = false;
      while (good != true)
	{
	  good = true;
	  posX = rand() % (_width - 1)  + 1;
	  posY = rand() % (_height - 1)  + 1;
	  try{
	    checkPlayerZone(posX, posY, _width / playerNbr, _height / playerNbr);
	  }catch (const std::range_error& e){
	    good = false;
	  }
	}
      spawnPlayer(posX, posY);
      playerNbr--;
    }
}

void MapGen::checkPlayerZone(int posX, int posY, int sizeX, int sizeY) //TODO verifier le bon fonctionnement
{

  int	tmpX;
  int	tmpY = posY;
  int	tmpSizeX = sizeX;

  while (tmpY > posY - sizeY && tmpY > 0)
    {
      tmpX = posX - sizeX;
      if (tmpX < 0)
	tmpX = 0;
      while (tmpX < posX + sizeX && tmpX < _width)
	{
	  if (_pMap[std::make_pair(tmpX, tmpY)] != NULL)
	    throw std::range_error("zone already occupied");
	  tmpX++;
	}
      sizeX--;
      tmpY--;
    }

  sizeX = tmpSizeX;
  tmpY = posY;

  while (tmpY < (posY + sizeY) && tmpY < _height)
    {
      tmpX = posX - sizeX;
      if (tmpX < 0)
        tmpX = 0;
      while (tmpX < posX + sizeX && tmpX < _width)
        {
          if (_pMap[std::make_pair(tmpX, tmpY)] != NULL)
            throw std::range_error("zone already occupied");
          tmpX++;
        }
      sizeX--;
      tmpY++;
    }
}
