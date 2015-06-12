//
// Lua.cpp for  in /home/charie_p/rendu/cpp_bomberman/sources/Lua
//
// Made by Pierre Charie
// Login   <charie_p@epitech.net>

//
// Started on  Wed May 27 11:31:12 2015 Pierre Charie
// Last update Fri Jun 12 23:53:50 2015 Jordan Chazottes
//

template <typename T>
MapGen<T>::MapGen()
{
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

template <typename T>
MapGen<T>::~MapGen()
{
}


template <typename T>
std::map<std::pair<int, int>, IEntity<T> *> MapGen<T>::getMap() const
{
  return (_map);
}

template <typename T>
std::map<std::pair<int, int>, IEntity<T> *> MapGen<T>::getPMap() const
{
  return (_pMap);
}

template <typename T>
std::string MapGen<T>::luaMapLoad(std::string fileLoad, std::string functionName)
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


template <typename T>
std::map<std::pair<int, int>, IEntity<T> *> MapGen<T>::mapGenerate(int width, int height)
{
  std::string   mapLua;
  int           i = 0;
  int           x = 0, y = 0;
  std::map<std::pair<int, int>, IEntity<T> *> gameMap;

  _width = width;
  _height = height;

  mapLua = luaMapLoad("./sources/Scripts/map/maprandom.lua", "serializeMap");

    while (mapLua[i])
    {
      std::stringstream ssType;
      IEntity<T> *item;
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

template <typename T>
std::map<std::pair<int, int>, IEntity<T> *>	MapGen<T>::playerMapGenerate(int playerNbr)
{
  std::map<std::pair<int, int>, IEntity<T> *>	playerMap;

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

template <typename T>
void                                                     MapGen<T>::spawnPlayer(int posX, int posY)
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
      if (_map[std::make_pair(posX, posY)])
	if (_map[std::make_pair(posX, posY)]->getType() != MAPWALL)
	  _map[std::make_pair(posX, posY)] = NULL;
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

template <typename T>
void                                                     MapGen<T>::spawnRandomPlayer(int playerNbr)
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

template <typename T>
void MapGen<T>::checkPlayerZone(int posX, int posY, int sizeX, int sizeY) //TODO verifier le bon fonctionnement
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

template <typename T>
void                                                          MapGen<T>::spawnTwoPlayer()
{
  int   random = rand() % 4 + 1;

 (this->*_spawnTwoM[random])();

}

template <typename T>
void                                                          MapGen<T>::spawnThreePlayer()
{
  int random = rand() % 4 + 1;

 (this->*_spawnThreeM[random])();

}

template <typename T>
void                                                          MapGen<T>::spawnFourPlayer()
{
  spawnPlayer(1, _height - 1);
  spawnPlayer(_width - 1, 1);
  spawnPlayer(1, 1);
  spawnPlayer(_width - 1, _height - 1);
}

template <typename T>
void                                                          MapGen<T>::spawnFivePlayer()
{
  std::cout << "TEEEEST\n";
  spawnPlayer(1, _height - 1);
  spawnPlayer(_width - 1, 1);
  spawnPlayer(1, 1);
  spawnPlayer(_width - 1, _height - 1);
  spawnPlayer(_width / 2, _height / 2);
}

template <typename T>
void                                                          MapGen<T>::spawnManyPlayer()
{
  spawnPlayer(1, _height - 1);
  spawnPlayer(_width - 1, 1);
  spawnPlayer(1, 1);
  spawnPlayer(_width - 1, _height - 1);
  spawnPlayer(_width / 2, _height / 2);
  spawnRandomPlayer(_playerNbr - 5);
}

template <typename T>
void                                                          MapGen<T>::spawnTwoTopLeft()
{
  spawnPlayer(1,1);
  spawnPlayer(_width - 1, _height - 1);
}

template <typename T>
void                                                          MapGen<T>::spawnTwoTopRight()
{
  spawnPlayer(_width - 1, 1);
  spawnPlayer(1, _height - 1);
}

template <typename T>
void                                                          MapGen<T>::spawnTwoBottomRight()
{
  spawnPlayer(1, _height - 1);
  spawnPlayer(_width - 1, 1);
}

template <typename T>
void                                                          MapGen<T>::spawnTwoBottomLeft()
{
  spawnPlayer(_width - 1, _height - 1);
  spawnPlayer(1, 1);
}

template <typename T>
void                                                          MapGen<T>::spawnThreeTopLeft()
{
      spawnPlayer(1,1);
      spawnPlayer(_width - 1, _height - 1);
      spawnPlayer(1, _height - 1);
}

template <typename T>
void                                                          MapGen<T>::spawnThreeTopRight()
{
      spawnPlayer(_width - 1, 1);
      spawnPlayer(1, _height - 1);
      spawnPlayer(1, 1);

}

template <typename T>
void                                                          MapGen<T>::spawnThreeBottomLeft()
{
      spawnPlayer(1, _height - 1);
      spawnPlayer(_width - 1, 1);
      spawnPlayer(_width - 1, _height - 1);
}

template <typename T>
void                                                          MapGen<T>::spawnThreeBottomRight()
{
      spawnPlayer(_width - 1, _height - 1);
      spawnPlayer(1, 1);
      spawnPlayer(_width - 1, 1);
}
