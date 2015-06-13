
template	<typename T>
EventManager<T>::EventManager(IGUI<T> &gui, ISafeQueue<IEntity<T> *> &drawQueue,
			      std::map<std::pair<int, int>, IEntity<T> *> &entityMap,
			      std::map<std::pair<int, int>, IEntity<T> *> &characterMap,
			      Factory<T> &factory, ICondVar &AICondVar, SoundManager &sM) : _gui(gui), _drawQueue(drawQueue), _entityMap(entityMap), _characterMap(characterMap), _factory(factory), _sM(sM)
{
  _end = false;
  _eventCondVar = new CondVar(_eventMutex);
  _eventQueue = new SafeQueue<std::pair<EventManager<T>::eEvent, IEntity<T> *> >();
  _pollEventThread = new Thread();
  _pollEventThread->create(&poll_event<T>, reinterpret_cast<void *>(this));
  _AIPool = new ThreadPool<AInt<T>, T>(3); // nb AI
  (void)AICondVar;
  _AIPool->addTask(new AInt<T>(10, 10, _characterMap, _entityMap, /*IEntity*/_characterMap[std::make_pair(-1, -1)], *_eventQueue, *_eventCondVar, AICondVar));
  _eventPtr[EventManager<T>::BOMBCREATION] = &EventManager<T>::bombCreation;
  _eventPtr[EventManager<T>::BOMBDESTRUCTION] = &EventManager<T>::bombDestruction;
  _eventPtr[EventManager<T>::FLAMEDESTRUCTION] = &EventManager<T>::flameDestruction;
  _eventPtr[EventManager<T>::INCREASEBOMBSTOCK] = &EventManager<T>::increaseBombStock;
  _eventPtr[EventManager<T>::UP] = &EventManager<T>::moveUp;
  _eventPtr[EventManager<T>::DOWN] = &EventManager<T>::moveDown;
  _eventPtr[EventManager<T>::LEFT] = &EventManager<T>::moveLeft;
  _eventPtr[EventManager<T>::RIGHT] = &EventManager<T>::moveRight;
  _eventPtr[EventManager<T>::ITEMDROP] = &EventManager<T>::itemDrop;
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
}

template	<typename T>
EventManager<T>::~EventManager(void)
{
  _end = true;
  delete _AIPool;
  delete _eventCondVar;
  delete _eventQueue;
  delete _pollEventThread;
}

template	<typename T>
bool		EventManager<T>::update(void)
{
  std::pair<EventManager<T>::eEvent, IEntity<T>*>	event;
  bool							pollEventUpdate = false;
  bool							timeUpdate;

  _eventCondVar->timedwait(10000000);
  std::cout << "update" << std::endl;
  _gui.update();
  while (_eventQueue->tryPop(&event) == true)
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

  while (!_eventTime.empty() && std::get<0>(_eventTime[0]) <= _gui.getElapsedTime())
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
      if (key != NONE)
	{
	  if (key == QUIT)
	    _end = true;
	  else if (key <= BOMB1)
	    _eventQueue->push(std::make_pair(_keyMap[key], _characterMap[std::make_pair(-1, -1)]));
	  else
	    _eventQueue->push(std::make_pair(_keyMap[key], _characterMap[std::make_pair(-2, -2)]));
	  _eventCondVar->signal();
	}
    }
  _eventCondVar->signal();
}

template	<typename T>
void		EventManager<T>::bombCreation(IEntity<T> *player)
{
  IEntity<T>	*bomb;

  if (reinterpret_cast<IPlayer<T> *>(player)->getBombStock() == 0)
    return;
  std::cout << "BOMB CREATION" << std::endl;
  reinterpret_cast<IPlayer<T> *>(player)->setBombStock(reinterpret_cast<IPlayer<T> *>(player)->getBombStock() - 1);
  bomb = _factory.createEntity(BOMB, player->getPosX(), player->getPosY());
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

  std::cout << "BOMB DESTRUCTION" << std::endl;
  _entityMap[std::make_pair(bomb->getPosX(), bomb->getPosY())] = NULL;
  time = _gui.getElapsedTime() + 1;
  burn(bomb->getPosX() + 1, bomb->getPosY(), bomb->getPosX() + 2, bomb->getPosY(), time);
  burn(bomb->getPosX() - 1, bomb->getPosY(), bomb->getPosX() - 2, bomb->getPosY(), time);
  burn(bomb->getPosX(), bomb->getPosY() + 1, bomb->getPosX(), bomb->getPosY() + 2, time);
  burn(bomb->getPosX(), bomb->getPosY() - 1, bomb->getPosX(), bomb->getPosY() - 2, time);
  burn(bomb->getPosX(), bomb->getPosY(), time);
  _sM.playSound(S_EXPLOSION);
}

template	<typename T>
bool		EventManager<T>::collider(IEntity<T> *p, IEntity<T> *obj, double toX, double toY)
{
  std::cout << "COLLIDER" << std::endl;
  if (obj == NULL)
    std::cout << "NULL" << std::endl;
  if (obj != NULL)
    std::cout << obj->getType() << std::endl;
  if (obj == NULL)
    return (true);
  (void)p;
  (void)toX;
  (void)toY;
  // else
  //   {
  //     if ((p->getPosX() + toX) > (obj->getPosX() + obj->getHitboxSize()) || (p->getPosY() + toY) > (obj->getPosY() + obj->getHitboxSize()))
  // 	return (false);
  //     else
  // 	return (true);
  //   }
  return false;
}

template	<typename T>
void		EventManager<T>::moveUp(IEntity<T> *player)
{
  std::cout << "UPKEY" << std::endl;
  if (collider(player, _entityMap[std::make_pair(static_cast<int>(player->getPosX()), static_cast<int>(player->getPosY() + 1))], 0, 1) == true)
    {
      player->setRotation(T(0, 0, 0));
      player->setPosY(player->getPosY() + 1);
      player->setPosition(glm::vec3(player->getPosX(), 0, player->getPosY()));
    }
  _drawQueue.push(player);
}

template	<typename T>
void		EventManager<T>::moveDown(IEntity<T> *player)
{
  std::cout << "DOWNKEY" << std::endl;
  if (collider(player, _entityMap[std::make_pair(static_cast<int>(player->getPosX()), static_cast<int>(player->getPosY() - 1))], 0, 1) == true)
    {
      player->setRotation(T(0, 180, 0));
      player->setPosY(player->getPosY() - 1);
      player->setPosition(glm::vec3(player->getPosX(), 0, player->getPosY()));
    }
  _drawQueue.push(player);
}

template	<typename T>
void		EventManager<T>::moveLeft(IEntity<T> *player)
{
  std::cout << "LEFTKEY" << std::endl;
  if (collider(player, _entityMap[std::make_pair(static_cast<int>(player->getPosX() + 1), static_cast<int>(player->getPosY()))], 1, 0) == true)
    {
      player->setRotation(T(0, 90, 0));
      player->setPosX(player->getPosX() + 1);
      player->setPosition(glm::vec3(player->getPosX(), 0, player->getPosY()));
    }
      _drawQueue.push(player);
}

template	<typename T>
void		EventManager<T>::moveRight(IEntity<T> *player)
{
  std::cout << "RIGHTKEY" << std::endl;
  if (collider(player, _entityMap[std::make_pair(static_cast<int>(player->getPosX() - 1), static_cast<int>(player->getPosY()))], 1, 0) == true)
    {
      player->setRotation(T(0, 270, 0));
      player->setPosX(player->getPosX() - 1);
      player->setPosition(glm::vec3(player->getPosX(), 0, player->getPosY()));
    }
  _drawQueue.push(player);
}

template	<typename T>
void		EventManager<T>::flameDestruction(IEntity<T> *flame)
{
  std::cout << "FLAME DESTRUCTION" << std::endl;
  _entityMap[std::make_pair(flame->getPosX(), flame->getPosY())] = NULL;
  delete flame;
}

template	<typename T>
void		EventManager<T>::increaseBombStock(IEntity<T> *player)
{
   reinterpret_cast<IPlayer<T> *>(player)->setBombStock(reinterpret_cast<IPlayer<T> *>(player)->getBombStock() + 1);
}

template	<typename T>
void		EventManager<T>::itemDrop(IEntity<T> *item)
{
  //add properties of item to player
  _entityMap[std::make_pair(item->getPosX(), item->getPosY())] = NULL;
  delete item;
}

template	<typename T>
void		EventManager<T>::burn(int x1, int y1, int x2, int y2, double time)
{
  if (_entityMap[std::make_pair(x1, y1)] == NULL)
    {
      burnEntity(x1, y1, time);
      if (_entityMap[std::make_pair(x2, y2)] == NULL ||
	  _entityMap[std::make_pair(x2, y2)]->isBreakable() == true)
	burnEntity(x2, y2, time);
    }
  else
    if (_entityMap[std::make_pair(x1, y1)]->isBreakable() == true)
      burnEntity(x1, y1, time);
}

template	<typename T>
void		EventManager<T>::burn(int x, int y, double time)
{
  if (_entityMap[std::make_pair(x, y)] == NULL ||
      _entityMap[std::make_pair(x, y)]->isBreakable() == true)
    burnEntity(x, y, time);
}

template	<typename T>
void		EventManager<T>::burnEntity(int x, int y, double time)
{
  if (_entityMap[std::make_pair(x, y)] != NULL)
    {
      delete _entityMap[std::make_pair(x, y)];
      _entityMap[std::make_pair(x, y)] = NULL;
    }
  /*if (_characterMap[std::make_pair(x, y)] != NULL)
    {
      delete _characterMap[std::make_pair(x, y)];
      _characterMap[std::make_pair(x, y)] = NULL;
      }*/
  flameCreation(x, y, time);
}

template	<typename T>
void		EventManager<T>::flameCreation(int x, int y, double time)
{
  IEntity<T>	*flame;

  std::cout << "FLAME CREATION" << std::endl;
  flame = _factory.createEntity(FLAME, x, y);
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
/*
template <class T>
ICondVar        &EventManager<T>::getEventCondVar()
{
  return (_eventCondVar);
}

template <class T>
ISafeQueue<std::pair<EventManager<T>::eEvent, IEntity<T> *> >	&EventManager<T>::getEventCondVar()
{
  return (_eventCondVar);
  }*/
