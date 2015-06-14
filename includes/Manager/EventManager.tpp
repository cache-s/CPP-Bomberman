
template	<typename T>
EventManager<T>::EventManager(IGUI<T> &gui, ISafeQueue<IEntity<T> *> &drawQueue,
			      std::map<std::pair<int, int>, IEntity<T> *> &entityMap,
			      std::map<std::pair<int, int>, IEntity<T> *> &characterMap,
			      Factory<T> &factory, ICondVar &AICondVar, SoundManager &sM, Settings &settings) : _gui(gui), _drawQueue(drawQueue), _entityMap(entityMap), _characterMap(characterMap), _factory(factory), _AICondVar(AICondVar), _sM(sM), _settings(settings)
{
  _end = false;
  _win = false;
  _eventCondVar = new CondVar(_eventMutex);
  _eventQueue = new SafeQueue<std::pair<EventManager<T>::eEvent, IEntity<T> *> >();
  _pollEventThread = new Thread();
  _pollEventThread->create(&poll_event<T>, reinterpret_cast<void *>(this));
  srand(time(NULL));
  _AIPool = NULL;
  _eventPtr[EventManager<T>::BOMBCREATION] = &EventManager<T>::bombCreation;
  _eventPtr[EventManager<T>::BOMBDESTRUCTION] = &EventManager<T>::bombDestruction;
  _eventPtr[EventManager<T>::FLAMEDESTRUCTION] = &EventManager<T>::flameDestruction;
  _eventPtr[EventManager<T>::INCREASEBOMBSTOCK] = &EventManager<T>::increaseBombStock;
  _eventPtr[EventManager<T>::UP] = &EventManager<T>::moveUp;
  _eventPtr[EventManager<T>::DOWN] = &EventManager<T>::moveDown;
  _eventPtr[EventManager<T>::LEFT] = &EventManager<T>::moveLeft;
  _eventPtr[EventManager<T>::RIGHT] = &EventManager<T>::moveRight;
  _eventPtr[EventManager<T>::MUTE] = &EventManager<T>::mute;
  _timeMap[BOMB] = EventManager<T>::BOMBDESTRUCTION;
  _timeMap[FLAME] = EventManager<T>::FLAMEDESTRUCTION;
  _timeMap[PLAYER] = EventManager<T>::INCREASEBOMBSTOCK;
  _keyMap[UP1] = EventManager<T>::UP;
  _keyMap[DOWN1] = EventManager<T>::DOWN;
  _keyMap[LEFT1] = EventManager<T>::LEFT;
  _keyMap[RIGHT1] = EventManager<T>::RIGHT;
  _keyMap[BOMB1] = EventManager<T>::BOMBCREATION;
  _keyMap[UP2] = EventManager<T>::UP;
  _keyMap[DOWN2] = EventManager<T>::DOWN;
  _keyMap[LEFT2] = EventManager<T>::LEFT;
  _keyMap[RIGHT2] = EventManager<T>::RIGHT;
  _keyMap[BOMB2] = EventManager<T>::BOMBCREATION;
  _keyMap[MUTEGAME] = EventManager<T>::MUTE;
  _itemPtr[BBOMBNUMBER] = &EventManager<T>::itemBombNumber;
  _itemPtr[BSPEED] = &EventManager<T>::itemSpeed;
  _itemPtr[BRADIUS] = &EventManager<T>::itemRadius;
}

template	<typename T>
EventManager<T>::~EventManager(void)
{
  _end = true;
  if (_AIPool != NULL)
    delete _AIPool;
  delete _eventCondVar;
  delete _eventQueue;
  _pollEventThread->cancel();
  delete _pollEventThread;
}

template	<typename T>
void		EventManager<T>::init()
{
  int nb = 0;
  int x = 0;
  int y = 0;

  _p1Alive = true;
  if (_settings.getPlayerNumber() == 2)
    _p2Alive = true;
  else
    _p2Alive = false;
  _nbAI = _settings.getAINumber();
  _AIPool = new ThreadPool<AInt<T>, T>(_settings.getAINumber());
  if (_settings.getPlayerNumber() == 1 && _settings.getAINumber() > 0)
    {
      _AIPool->addTask(new AInt<T>(_settings.getMapSize(), _settings.getMapSize(), _characterMap, _entityMap, _characterMap[std::make_pair(-2, -2)], *_eventQueue, *_eventCondVar, _AICondVar));
      nb++;
    }
  while (nb < _settings.getAINumber())
    {
      while (_characterMap[std::make_pair(x, y)] == NULL)
	{
	  y++;
	  if (y == _settings.getMapSize())
	    {
	      y = 0;
	      x++;
	    }
	}
      if ((x != (_characterMap[std::make_pair(-1, -1)])->getPosX() || y != (_characterMap[std::make_pair(-1, -1)])->getPosY()) && (x != (_characterMap[std::make_pair(-2, -2)])->getPosX() || y != (_characterMap[std::make_pair(-2, -2)])->getPosY()))
	{
	  _AIPool->addTask(new AInt<T>(_settings.getMapSize(), _settings.getMapSize(), _characterMap, _entityMap, _characterMap[std::make_pair(x, y)], *_eventQueue, *_eventCondVar, _AICondVar));
	  nb++;
	}
      y++;
    }
}

template	<typename T>
bool		EventManager<T>::update(void)
{
  std::pair<EventManager<T>::eEvent, IEntity<T>*>	event;
  bool							pollEventUpdate = false;
  bool							timeUpdate;

  _eventCondVar->timedwait(10000000);
  _gui.update();
  while (!_end && _eventQueue->tryPop(&event) == true)
    {
      (this->*_eventPtr[std::get<0>(event)])(std::get<1>(event));
      pollEventUpdate = true;
    }
  timeUpdate = timeCheck();
  return (pollEventUpdate || timeUpdate);
}

template	<typename T>
bool		EventManager<T>::timeCheck(void)
{
  bool		update = false;

  while (!_end && !_eventTime.empty() && std::get<0>(_eventTime[0]) <= _gui.getElapsedTime())
    {
      _eventQueue->push(std::make_pair(_timeMap[(std::get<1>(_eventTime[0]))->getType()], std::get<1>(_eventTime[0])));
      _eventTime.erase(_eventTime.begin());
      update = true;
    }
  if (update)
    _eventCondVar->signal();
  return (update);
}

template	<typename T>
void		*poll_event(void *c)
{
  reinterpret_cast<EventManager<T> *>(c)->pollEvent();
  return (NULL);
}

template	<typename T>
void		EventManager<T>::pollEvent(void)
{
  eKey		key;

  while (!_end)
    {
      key = _gui.pollEvent();
      if (key != NONE && !(key >= UP2 && key <= BOMB2 && _settings.getPlayerNumber() == 1))
	{
	  if (key == QUIT)
	    _end = true;
	  else if (key <= BOMB1)
	    _eventQueue->push(std::make_pair(_keyMap[key], _characterMap[std::make_pair(-1, -1)]));
	  else
	    _eventQueue->push(std::make_pair(_keyMap[key], _characterMap[std::make_pair(-2, -2)]));
	  _eventCondVar->signal();
	}
      _eventCondVar->signal();
    }
}

template	<typename T>
void		EventManager<T>::bombCreation(IEntity<T> *player)
{
  IEntity<T>	*bomb;

  if (reinterpret_cast<IPlayer<T> *>(player)->getBombStock() == 0)
    return;
  reinterpret_cast<IPlayer<T> *>(player)->setBombStock(reinterpret_cast<IPlayer<T> *>(player)->getBombStock() - 1);
  bomb = _factory.createEntity(BOMB, player->getPosX(), player->getPosY());
  reinterpret_cast<IBomb<T> *>(bomb)->setRadius(reinterpret_cast<IPlayer<T> *>(player)->getRadius());
  _eventTime.push_back(std::make_pair(_gui.getElapsedTime() + 3, bomb));
  _eventTime.push_back(std::make_pair(_gui.getElapsedTime() + 3, player));
  std::sort(_eventTime.begin(), _eventTime.end());
  _entityMap[std::make_pair(player->getPosX(), player->getPosY())] = bomb;
  _sM.playSound(S_BOMB);
  _drawQueue.push(bomb);
}

template	<typename T>
void		EventManager<T>::bombDestruction(IEntity<T> *bomb)
{
  double	time;

  _entityMap[std::make_pair(bomb->getPosX(), bomb->getPosY())] = NULL;
  time = _gui.getElapsedTime() + 1;
  burn(bomb->getPosX(), bomb->getPosY(), 1, 0, time, reinterpret_cast<IBomb<T> *>(bomb)->getRadius());
  burn(bomb->getPosX(), bomb->getPosY(), -1, 0, time, reinterpret_cast<IBomb<T> *>(bomb)->getRadius());
  burn(bomb->getPosX(), bomb->getPosY(), 0, 1, time, reinterpret_cast<IBomb<T> *>(bomb)->getRadius());
  burn(bomb->getPosX(), bomb->getPosY(), 0, -1, time, reinterpret_cast<IBomb<T> *>(bomb)->getRadius());
  burn(bomb->getPosX(), bomb->getPosY(), 0, 0, time, 1);
  _sM.playSound(S_EXPLOSION);
}

template	<typename T>
bool		EventManager<T>::collider(IEntity<T> *player, double toX, double toY)
{
  if (_entityMap[std::make_pair(toX, toY)] == NULL && _characterMap[std::make_pair(toX, toY)] == NULL)
    return (true);
  if (_entityMap[std::make_pair(toX, toY)] != NULL)
    {
      if ((_entityMap[std::make_pair(toX, toY)])->getType() >= BBOMBNUMBER && (_entityMap[std::make_pair(toX, toY)])->getType() <= BRADIUS)
	{
	  itemDrop(player, _entityMap[std::make_pair(toX, toY)]);
	  return (true);
	}
      if ((_entityMap[std::make_pair(toX, toY)])->isCrossable())
	{
	  if ((_entityMap[std::make_pair(toX, toY)])->getType() == FLAME)
	    {
	      killPlayer(player);
	      return (false);
	    }
	  return (true);
	}
    }
  return (false);
}

template	<typename T>
void		EventManager<T>::moveUp(IEntity<T> *player)
{
  if (collider(player, player->getPosX(), player->getPosY() + 1) == true)
    {
      _characterMap[std::make_pair(player->getPosX(), player->getPosY())] = NULL;
      _characterMap[std::make_pair(player->getPosX(), player->getPosY() + 1)] = player;
      player->setRotation(T(0, 0, 0));
      player->setPosY(player->getPosY() + 1);
      player->setPosition(glm::vec3(player->getPosX(), 0, player->getPosY()));
      _drawQueue.push(player);
    }
}

template	<typename T>
void		EventManager<T>::moveDown(IEntity<T> *player)
{
  if (collider(player, player->getPosX(), player->getPosY() - 1) == true)
    {
      _characterMap[std::make_pair(player->getPosX(), player->getPosY())] = NULL;
      _characterMap[std::make_pair(player->getPosX(), player->getPosY() - 1)] = player;
      player->setRotation(T(0, 180, 0));
      player->setPosY(player->getPosY() - 1);
      player->setPosition(glm::vec3(player->getPosX(), 0, player->getPosY()));
      _drawQueue.push(player);
    }
}

template	<typename T>
void		EventManager<T>::moveLeft(IEntity<T> *player)
{
  if (collider(player, player->getPosX() + 1, player->getPosY()) == true)
    {
      _characterMap[std::make_pair(player->getPosX(), player->getPosY())] = NULL;
      _characterMap[std::make_pair(player->getPosX() + 1, player->getPosY())] = player;
      player->setRotation(T(0, 90, 0));
      player->setPosX(player->getPosX() + 1);
      player->setPosition(glm::vec3(player->getPosX(), 0, player->getPosY()));
      _drawQueue.push(player);
    }
}

template	<typename T>
void		EventManager<T>::moveRight(IEntity<T> *player)
{
  if (collider(player, player->getPosX() - 1, player->getPosY()) == true)
    {
      _characterMap[std::make_pair(player->getPosX(), player->getPosY())] = NULL;
      _characterMap[std::make_pair(player->getPosX() - 1, player->getPosY())] = player;
      player->setRotation(T(0, 270, 0));
      player->setPosX(player->getPosX() - 1);
      player->setPosition(glm::vec3(player->getPosX(), 0, player->getPosY()));
      _drawQueue.push(player);
    }
}

template	<typename T>
void		EventManager<T>::flameDestruction(IEntity<T> *flame)
{
  _entityMap[std::make_pair(flame->getPosX(), flame->getPosY())] = NULL;
  if (reinterpret_cast<IFlame<T> *>(flame)->isDrop())
    generateItem(flame->getPosX(), flame->getPosY());
  delete flame;
}

template	<typename T>
void		EventManager<T>::increaseBombStock(IEntity<T> *player)
{
   reinterpret_cast<IPlayer<T> *>(player)->setBombStock(reinterpret_cast<IPlayer<T> *>(player)->getBombStock() + 1);
}

template	<typename T>
void		EventManager<T>::itemDrop(IEntity<T> *player, IEntity<T> *item)
{
  (this->*_itemPtr[item->getType()])(player);
  _entityMap[std::make_pair(item->getPosX(), item->getPosY())] = NULL;
  delete item;
}

template	<typename T>
void		EventManager<T>::burn(int bombX, int bombY, int toX, int toY, double time, int bombRadius)
{
  int		radius = 1;
  int		burnX = toX;
  int		burnY = toY;

  while (radius <= bombRadius)
    {
      if (_entityMap[std::make_pair(bombX + burnX, bombY + burnY)] == NULL)
	burnEntity(bombX + burnX, bombY + burnY, time);
      else
	{
	  if (_entityMap[std::make_pair(bombX + burnX, bombY + burnY)]->isBreakable() == true)
	    burnEntity(bombX + burnX, bombY + burnY, time);
	  return ;
	}
      radius++;
      burnX += toX;
      burnY += toY;
    }
}

template	<typename T>
void		EventManager<T>::burnEntity(int x, int y, double time)
{
  bool drop = false;

  if (_entityMap[std::make_pair(x, y)] != NULL)
    {
      delete _entityMap[std::make_pair(x, y)];
      _entityMap[std::make_pair(x, y)] = NULL;
      drop = true;
    }
  if (_characterMap[std::make_pair(x, y)] != NULL)
    killPlayer(_characterMap[std::make_pair(x, y)]);
  flameCreation(x, y, time, drop);
}

template	<typename T>
void		EventManager<T>::killPlayer(IEntity<T> *player)
{
  if (player->getPosX() == (_characterMap[std::make_pair(-1, -1)])->getPosX() && player->getPosY() == (_characterMap[std::make_pair(-1, -1)])->getPosY())
      _p1Alive = false;
  else
    if (player->getPosX() == (_characterMap[std::make_pair(-1, -1)])->getPosX() && player->getPosY() == (_characterMap[std::make_pair(-2, -2)])->getPosY())
      {
	if (_settings.getPlayerNumber() == 2)
	  _p2Alive = false;
	else
	  _nbAI -= 1;
      }
    else
      _nbAI -= 1;
    }
  _characterMap[std::make_pair(player->getPosX(), player->getPosY())] = NULL;
  usleep(1000);
  delete player;
  if (!_p1Alive && !_p2Alive)
    {
      _end = true;
      _win = false;
    }
  if (((_p1Alive && !_p2Alive) || (!_p1Alive && _p2Alive)) && _nbAI == 0)
    {
      _end = true;
      _win = true;
    }
}

template	<typename T>
void		EventManager<T>::flameCreation(int x, int y, double time, bool drop)
{
  IEntity<T>	*flame;

  flame = _factory.createEntity(FLAME, x, y);
  reinterpret_cast<IFlame<T> *>(flame)->setDrop(drop);
  _eventTime.push_back(std::make_pair(time, flame));
  std::sort(_eventTime.begin(), _eventTime.end());
  _entityMap[std::make_pair(x, y)] = flame;
  _drawQueue.push(flame);
}

template	<typename T>
void		EventManager<T>::mute(IEntity<T> *player)
{
  (void)player;
  if (_sM.getVolume() == 0)
    _sM.unmute();
  else
    _sM.mute();
}

template	<typename T>
bool		EventManager<T>::isEnd() const
{
  return (_end);
}

template	<typename T>
void		EventManager<T>::generateItem(int x, int y)
{
  IEntity<T>	*item;

  if ((rand() % 100) < 30)
    {
      item = _factory.createEntity(static_cast<eEntityType>(rand() % 3 + 10), x, y);
      _entityMap[std::make_pair(x, y)] = item;
      _drawQueue.push(item);
    }
}

template	<typename T>
void		EventManager<T>::itemBombNumber(IEntity<T> *player)
{
  reinterpret_cast<IPlayer<T> *>(player)->setBombStock(reinterpret_cast<IPlayer<T> *>(player)->getBombStock() + 1);
}

template	<typename T>
void		EventManager<T>::itemSpeed(__attribute__((unused)) IEntity<T> *player)
{

}

template	<typename T>
void		EventManager<T>::itemRadius(IEntity<T> *player)
{
  reinterpret_cast<IPlayer<T> *>(player)->setRadius(reinterpret_cast<IPlayer<T> *>(player)->getRadius() + 1);
}

template	<typename T>
bool		EventManager<T>::isP1Alive() const
{
  return (_p1Alive);
}

template	<typename T>
bool		EventManager<T>::isP2Alive() const
{
  return (_p2Alive);
}

template	<typename T>
int		EventManager<T>::getNbAI() const
{
  return (_nbAI);
}

template	<typename T>
bool		EventManager<T>::isWin() const
{
  return (_win);
}
