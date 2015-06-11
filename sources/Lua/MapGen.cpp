//
// Lua.cpp for  in /home/charie_p/rendu/cpp_bomberman/sources/Lua
//
// Made by Pierre Charie
// Login   <charie_p@epitech.net>

//
// Started on  Wed May 27 11:31:12 2015 Pierre Charie
// Last update Wed Jun 10 19:50:25 2015 Pierre Charie
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
  std::cout << "LE JEUDADA\n";

  _spawnM[2] = &MapGen::spawnTwoPlayer;
  _spawnM[3] = &MapGen::spawnThreePlayer;
  _spawnM[4] = &MapGen::spawnFourPlayer;
  _spawnM[5] = &MapGen::spawnFivePlayer;

  _spawnTwoM[1] = &MapGen::spawnTwoTopLeft;
  _spawnTwoM[2] = &MapGen::spawnTwoTopRight;
  _spawnTwoM[3] = &MapGen::spawnTwoBottomLeft;
  _spawnTwoM[4] = &MapGen::spawnTwoBottomRight;

  _spawnThreeM[1] = &MapGen::spawnThreeTopLeft;
  _spawnThreeM[2] = &MapGen::spawnThreeTopRight;
  _spawnThreeM[3] = &MapGen::spawnThreeBottomLeft;
  _spawnThreeM[4] = &MapGen::spawnThreeBottomRight;

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
  int           x = 0, y = 0;
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

  if (playerNbr > (_width * _height / 15))
    throw std::range_error("too many player for this size of map") ;

  _playerNbr = playerNbr;

  srand (time(NULL));


  if (_spawnM.find(playerNbr) != _spawnM.end())
    (this->*_spawnM[playerNbr])();
  else
    spawnManyPlayer();

  return _pMap;
}

void                                                     MapGen::spawnPlayer(int posX, int posY)
{
  static int						playerNb = 0;
  int							deltaX = _width / _playerNbr + 1;
  int							deltaY = _height / _playerNbr + 1;

  posX -= deltaX;
  posY -= deltaY;

  if (posX < 1)
    posX = 1;

  if (posY < 1)
    posY = 1;

  posX += rand() % deltaX;
  posY += rand() % deltaY;

  _pMap[std::make_pair(posX, posY)] = _fac.createEntity(PLAYER , posX, posY);

  if (playerNb == 0)
    _pMap[std::make_pair(-1, -1)] = _pMap[std::make_pair(posX, posY)];
  if (playerNb == 1)
    _pMap[std::make_pair(-2, -2)] = _pMap[std::make_pair(posX, posY)];

  if (posX > 0 && posY > 0 && posX < _width && posY < _height)
    {
      if (_map[std::make_pair(posX - 1, posY - 1)] != NULL)
	if (_map[std::make_pair(posX - 1, posY - 1)]->getType() != MAPWALL)
	  _map[std::make_pair(posX - 1, posY - 1)] = NULL;
      if (_map[std::make_pair(posX, posY - 1)] != NULL)
	if (_map[std::make_pair(posX, posY - 1)]->getType() != MAPWALL)
	  _map[std::make_pair(posX, posY - 1)] = NULL;
      if (_map[std::make_pair(posX + 1, posY - 1)])
	if (_map[std::make_pair(posX + 1, posY - 1)]->getType() != MAPWALL)
	  _map[std::make_pair(posX + 1, posY - 1)] = NULL;

      if (_map[std::make_pair(posX - 1, posY)])
	if (_map[std::make_pair(posX - 1, posY)]->getType() != MAPWALL)
	  _map[std::make_pair(posX - 1, posY)] = NULL;
      if (_map[std::make_pair(posX + 1, posY)])
	if (_map[std::make_pair(posX + 1, posY)]->getType() != MAPWALL)
	  _map[std::make_pair(posX + 1, posY)] = NULL;

      if (_map[std::make_pair(posX - 1, posY + 1)])
	if (_map[std::make_pair(posX - 1, posY + 1)]->getType() != MAPWALL)
	  _map[std::make_pair(posX - 1, posY + 1)] = NULL;
      if (_map[std::make_pair(posX, posY + 1)])
	if (_map[std::make_pair(posX, posY + 1)]->getType() != MAPWALL)
	  _map[std::make_pair(posX, posY + 1)] = NULL;
      if (_map[std::make_pair(posX + 1, posY + 1)])
	if (_map[std::make_pair(posX + 1, posY + 1)]->getType() != MAPWALL)
	  _map[std::make_pair(posX + 1, posY + 1)] = NULL;
    }
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

void                                                          MapGen::spawnTwoPlayer()
{
  int   random = rand() % 4 + 1;

 (this->*_spawnTwoM[random])();

}

void                                                          MapGen::spawnThreePlayer()
{
  int random = rand() % 4 + 1;

 (this->*_spawnThreeM[random])();

}

void                                                          MapGen::spawnFourPlayer()
{
  spawnPlayer(1, _height - 1);
  spawnPlayer(_width - 1, 1);
  spawnPlayer(1, 1);
  spawnPlayer(_width - 1, _height - 1);
}
void                                                          MapGen::spawnFivePlayer()
{
  std::cout << "TEEEEST\n";
  spawnPlayer(1, _height - 1);
  spawnPlayer(_width - 1, 1);
  spawnPlayer(1, 1);
  spawnPlayer(_width - 1, _height - 1);
  spawnPlayer(_width / 2, _height / 2);
}

void                                                          MapGen::spawnManyPlayer()
{
  spawnPlayer(1, _height - 1);
  spawnPlayer(_width - 1, 1);
  spawnPlayer(1, 1);
  spawnPlayer(_width - 1, _height - 1);
  spawnPlayer(_width / 2, _height / 2);
  spawnRandomPlayer(_playerNbr - 5);
}

void                                                          MapGen::spawnTwoTopLeft()
{
  spawnPlayer(1,1);
  spawnPlayer(_width - 1, _height - 1);
}

void                                                          MapGen::spawnTwoTopRight()
{
  spawnPlayer(_width - 1, 1);
  spawnPlayer(1, _height - 1);
}

void                                                          MapGen::spawnTwoBottomRight()
{
  spawnPlayer(1, _height - 1);
  spawnPlayer(_width - 1, 1);
}

void                                                          MapGen::spawnTwoBottomLeft()
{
  spawnPlayer(_width - 1, _height - 1);
  spawnPlayer(1, 1);
}

void                                                          MapGen::spawnThreeTopLeft()
{
      spawnPlayer(1,1);
      spawnPlayer(_width - 1, _height - 1);
      spawnPlayer(1, _height - 1);
}

void                                                          MapGen::spawnThreeTopRight()
{
      spawnPlayer(_width - 1, 1);
      spawnPlayer(1, _height - 1);
      spawnPlayer(1, 1);

}

void                                                          MapGen::spawnThreeBottomLeft()
{
      spawnPlayer(1, _height - 1);
      spawnPlayer(_width - 1, 1);
      spawnPlayer(_width - 1, _height - 1);
}

void                                                          MapGen::spawnThreeBottomRight()
{
      spawnPlayer(_width - 1, _height - 1);
      spawnPlayer(1, 1);
      spawnPlayer(_width - 1, 1);
}
