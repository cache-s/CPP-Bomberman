//
// EventManager.tpp for Bomberman in /home/porres_m/Projets/Cpp/Bomberman/cpp_bomberman
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Tue Jun  9 23:07:38 2015 Martin Porrès
// Last update Wed Jun 10 17:08:03 2015 Martin Porrès
//

template	<typename T>
EventManager<T>::EventManager(IGUI<T> &gui, ISafeQueue<IEntity<T> *> &drawQueue,
			      std::map<std::pair<int, int>, IEntity<T> *> &entityMap,
			      std::map<std::pair<int, int>, IEntity<T> *> &characterMap,
			      Factory<T> &factory) : _gui(gui), _drawQueue(drawQueue), _entityMap(entityMap), _characterMap(characterMap), _factory(factory)
{
  _end = false;
  _eventCondVar = new CondVar(_eventMutex);
  _eventQueue = new SafeQueue<std::pair<EventManager<T>::eEvent, IEntity<T> *> >();
  _pollEventThread = new Thread();
  _pollEventThread->create(&poll_event<T>, reinterpret_cast<void *>(this));
  _eventPtr[EventManager<T>::BOMBCREATION] = &EventManager<T>::bombCreation;
  _eventPtr[EventManager<T>::BOMBDESTRUCTION] = &EventManager<T>::bombDestruction;
  _eventPtr[EventManager<T>::FLAMEDESTRUCTION] = &EventManager<T>::flameDestruction;
  _eventPtr[EventManager<T>::INCREASEBOMBSTOCK] = &EventManager<T>::increaseBombStock;
  _eventPtr[EventManager<T>::UP] = &EventManager<T>::moveUp;
  _eventPtr[EventManager<T>::DOWN] = &EventManager<T>::moveDown;
  _eventPtr[EventManager<T>::LEFT] = &EventManager<T>::moveLeft;
  _eventPtr[EventManager<T>::RIGHT] = &EventManager<T>::moveRight;
  _eventPtr[EventManager<T>::ITEMDROP] = &EventManager<T>::itemDrop;
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
}

template	<typename T>
EventManager<T>::~EventManager(void)
{
  _end = true;
  _pollEventThread->join();
}

template	<typename T>
bool		EventManager<T>::update(void)
{
  std::pair<EventManager<T>::eEvent, IEntity<T>*>	event;
  bool							pollEventUpdate = false;
  bool							timeUpdate;

  _eventCondVar->timedwait(100000000);
  _gui.update();
  if (_eventQueue->tryPop(&event) == true)
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
      _eventCondVar->signal();
      _eventTime.erase(_eventTime.begin());
      update = true;
    }
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
  _drawQueue.push(bomb);
}

template	<typename T>
void		EventManager<T>::bombDestruction(IEntity<T> *bomb)
{
  std::cout << "BOMB DESTRUCTION" << std::endl;
  _entityMap[std::make_pair(bomb->getPosX(), bomb->getPosY())] = NULL;
  burn(bomb->getPosX() + 1, bomb->getPosY(), bomb->getPosX() + 2, bomb->getPosY());
  burn(bomb->getPosX() - 1, bomb->getPosY(), bomb->getPosX() - 2, bomb->getPosY());
  burn(bomb->getPosX(), bomb->getPosY() + 1, bomb->getPosX(), bomb->getPosY() + 2);
  burn(bomb->getPosX(), bomb->getPosY() - 1, bomb->getPosX(), bomb->getPosY() - 2);
  burn(bomb->getPosX(), bomb->getPosY());
}

template	<typename T>
void		EventManager<T>::moveUp(IEntity<T> *player)
{
  double	newX;

  std::cout << "MOVE UP" << std::endl;
  newX = player->getPosX() + 0.1;
  if (static_cast<int>(newX) > static_cast<int>(player->getPosX()))
    {
      _characterMap[std::make_pair(static_cast<int>(player->getPosX()), static_cast<int>(player->getPosY()))] = NULL;
      _characterMap[std::make_pair(static_cast<int>(newX), static_cast<int>(player->getPosY()))] = NULL;
    }
  player->setPosX(newX);
  _drawQueue.push(player);
}

template	<typename T>
void		EventManager<T>::moveDown(IEntity<T> *player)
{
  double	newX;

  std::cout << "MOVE DOWN" << std::endl;
  newX = player->getPosX() - 0.1;
  if (static_cast<int>(newX) < static_cast<int>(player->getPosX()))
    {
      _characterMap[std::make_pair(static_cast<int>(player->getPosX()), static_cast<int>(player->getPosY()))] = NULL;
      _characterMap[std::make_pair(static_cast<int>(newX), static_cast<int>(player->getPosY()))] = NULL;
    }
  player->setPosX(newX);
  _drawQueue.push(player);
}

template	<typename T>
void		EventManager<T>::moveLeft(IEntity<T> *player)
{
  double	newY;

  std::cout << "MOVE LEFT" << std::endl;
  newY = player->getPosY() + 0.1;
  if (static_cast<int>(newY) > static_cast<int>(player->getPosY()))
    {
      _characterMap[std::make_pair(static_cast<int>(player->getPosX()), static_cast<int>(player->getPosY()))] = NULL;
      _characterMap[std::make_pair(static_cast<int>(player->getPosX()), static_cast<int>(newY))] = NULL;
    }
  player->setPosY(newY);
  _drawQueue.push(player);
}

template	<typename T>
void		EventManager<T>::moveRight(IEntity<T> *player)
{
  double	newY;

  std::cout << "MOVE RIGHT" << std::endl;
  newY = player->getPosY() - 0.1;
  if (static_cast<int>(newY) < static_cast<int>(player->getPosY()))
    {
      _characterMap[std::make_pair(static_cast<int>(player->getPosX()), static_cast<int>(player->getPosY()))] = NULL;
      _characterMap[std::make_pair(static_cast<int>(player->getPosX()), static_cast<int>(newY))] = NULL;
    }
  player->setPosY(newY);
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
void		EventManager<T>::burn(int x1, int y1, int x2, int y2)
{
  if (_entityMap[std::make_pair(x1, y1)] == NULL ||
      _entityMap[std::make_pair(x1, y1)]->isBreakable() == true)
    {
      burnEntity(x1, y1);
      if (_entityMap[std::make_pair(x2, y2)] == NULL ||
	  _entityMap[std::make_pair(x2, y2)]->isBreakable() == true)
	burnEntity(x2, y2);
    }
}

template	<typename T>
void		EventManager<T>::burn(int x, int y)
{
  if (_entityMap[std::make_pair(x, y)] == NULL ||
      _entityMap[std::make_pair(x, y)]->isBreakable() == true)
    burnEntity(x, y);
}

template	<typename T>
void		EventManager<T>::burnEntity(int x, int y)
{
  if (_entityMap[std::make_pair(x, y)] != NULL)
    {
      delete _entityMap[std::make_pair(x, y)];
      _entityMap[std::make_pair(x, y)] = NULL;
    }
  if (_characterMap[std::make_pair(x, y)] != NULL)
    {
      delete _characterMap[std::make_pair(x, y)];
      _characterMap[std::make_pair(x, y)] = NULL;
    }
  flameCreation(x, y);
}

template	<typename T>
void		EventManager<T>::flameCreation(int x, int y)
{
  IEntity<T>	*flame;

  std::cout << "FLAME CREATION" << std::endl;
  flame = _factory.createEntity(FLAME, x, y);
  _eventTime.push_back(std::make_pair(_gui.getElapsedTime() + 1, flame));
  std::sort(_eventTime.begin(), _eventTime.end());
  _drawQueue.push(flame);
}

template	<typename T>
bool		EventManager<T>::isEnd() const
{
  return (_end);
}