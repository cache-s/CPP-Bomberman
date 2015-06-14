template <typename T>
AInt<T>::AInt(int width, int height, std::map<std::pair<int, int>, IEntity<T> *> &playerMap, std::map<std::pair<int, int>, IEntity<T> *> &gameMap, IEntity<T> *player, ISafeQueue<std::pair<typename EventManager<T>::eEvent, IEntity<T> *> > &eventQueue, ICondVar &eventCondVar, ICondVar &AICondVar) : _player(player), _playerMap(playerMap), _gameMap(gameMap), _eventQueue(eventQueue), _eventCondVar(eventCondVar), _AICondVar(AICondVar)
{
  _width = width;
  _height = height;

  _path = "./sources/Scripts/ai/ai.lua";
  _func = "move";
}

template <typename T>
AInt<T>::~AInt()
{

}

template <typename T>
std::string     AInt<T>::mapMerge()
{
  int   tmp;
  std::string result;

  int x = 0, y = 0;

  while (y < _height)
    {
      while (x < _width)
	{
          if (_gameMap[std::make_pair(x, y)] == NULL)
            if (_playerMap[std::make_pair(x, y)] == NULL)
              tmp = 0;
            else
	      {
		tmp = _playerMap[std::make_pair(x, y)]->getType();
		tmp = 5;
	      }
          else
	      {
		int mapCase = _gameMap[std::make_pair(x, y)]->getType();
		switch (mapCase)
		  {
		  case BRKWALL:
		    tmp = 1;
		    break;
		  case UBRKWALL:
		    tmp = 2;
		    break;
		  case MAPWALL:
		    tmp = 3;
		    break;

		  case BBOMBNUMBER:
		    tmp = 4;
		    break;
		  case BSPEED:
		    tmp = 4;
		    break;
		  case BRADIUS:
		    tmp = 4;
		    break;

		  case PLAYER:
		    tmp = 5;
		    break;
		  case ARTINT:
		    tmp = 5;
		    break;
		  case MONSTER:
		    tmp = 5;
		    break;

		  case FLAME:
		    tmp = 6;
		    break;
		  case BOMB:
		    tmp = 7;
		    break;
		  }
	      }
	  std::stringstream ss;
          ss << tmp;
          result += ss.str();
          x++;
        }
      y++;
      x = 0;
    }

  std::size_t found = result.find("7");
  int i = 0;


  while (found != std::string::npos)
    {

      result[found] = '6';
      result[found - 1] = '6';
      result[found - 2] = '6';
      result[found - 3] = '6';

      result[found - _width] = '6';
      result[found - _width * 2] = '6';
      result[found - _width * 3] = '6';

      result[found + 1] = '6';
      result[found + 2] = '6';
      result[found + 3] = '6';

      result[found + _width] = '6';
      result[found + _width * 2] = '6';
      result[found + _width * 3] = '6';
      i++;
      found = result.find("7", i);
    }

  return result;
}

template <typename T>
void            AInt<T>::move()
{
  lua_State*            L = luaL_newstate();
  int                   action;

  while (true)
    {
      _AICondVar.wait();
      luaL_openlibs(L);
      if (luaL_loadfile(L, _path.c_str()) || lua_pcall(L, 0, 0, 0))
	{
	  std:: cout << lua_tostring(L, -1);
	  throw std::runtime_error("Couldn't load the AI");
	}
      lua_getglobal(L, _func.c_str());
      if(!lua_isfunction(L,-1))
        {
          lua_pop(L,1);
	  std::string error;
          error = "Error, function doesn't exist";
          throw std::runtime_error(error);
        }
      std::string map = mapMerge();
      lua_pushstring(L, map.c_str());
      lua_pushinteger(L, _width);
      lua_pushinteger(L, _height);
      lua_pushinteger(L, _player->getPosX());
      lua_pushinteger(L, _player->getPosY());

      if (lua_pcall(L, 5, 1, 0) != 0)
        {
	  std::string error;
	  std::cout << "lua FAIL : " << lua_tostring(L, -1) << std::endl;
          error = "Error running LUA function";
	  throw std::runtime_error(error);
        }
      action = lua_tointeger(L, -1);
      lua_pop(L, 1);
      std::cout << "ACTION = " << action << std::endl;
      if (action == 101 || (action > 103 && action < 108))
	{
	  // switch (action)
	  //   {
	  //   case 102:
	  //     std::cout << "on bombe " << std::endl;
	  //     break;
	  //   case 104:
	  //     std::cout << "on monte" << std::endl;
	  //     break;
	  //   case 105:
	  //     std::cout << "on descend" << std::endl;
	  //     break;
	  //   case 106:
	  //     std::cout << "on va a gauche" << std::endl;
	  //     break;
	  //   case 107:
	  //     std::cout << "on va a droite" << std::endl;
	  //     break;
	  //   }
	  _eventQueue.push(std::make_pair(static_cast<typename EventManager<T>::eEvent>(action), _player));
	  _eventCondVar.signal();
	}
    }
}
