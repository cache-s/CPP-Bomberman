//
// EventManager.cpp for Bomberman in /home/porres_m/Projets/Cpp/Bomberman/cpp_bomberman/sources/Manager
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Sun May 24 18:13:31 2015 Martin Porrès
// Last update Tue Jun  2 18:13:18 2015 Martin Porrès
//

#include	"EventManager.hpp"

EventManager::EventManager(IGUI &gui, ISafeQueue<IEntity *> &drawQueue,
			   std::map<std::pair<int x, int y>, IEntity *entity> &entityMap,
			   std::map<std::pair<int x, int y>, IEntity *character> &characterMap) :
  _drawQueue(drawQueue),
  _gui(gui),
  _entityMap(entityMap),
  _characterMap(characterMap)
{
  _end = false;
  _pollEventThread()->create(&poll_event);
  _eventPtr[EventManager::BOMBCREATION] = &EventManager::bombCreation;
  _eventPtr[EventManager::UP] = &EventManager::moveUp;
  _eventPtr[EventManager::DOWN] = &EventManager::moveDown;
  _eventPtr[EventManager::LEFT] = &EventManager::moveLeft;
  _eventPtr[EventManager::RIGHT] = &EventManager::moveRight;
  _eventPtr[EventManager::ITEMDROP] = &EventManager::itemDrop;
  _eventPtr[BOMB] = &EventManager::bombDestruction;
  _eventPtr[FLAME] = &EventManager::flameDestruction;
  _eventPtr[1UP] = &EventManager::moveUp;
  _eventPtr[1DOWN] = &EventManager::moveDown;
  _eventPtr[1LEFT] = &EventManager::moveLeft;
  _eventPtr[1RIGHT] = &EventManager::moveRight;
  _eventPtr[1BOMB] = &EventManager::bombCreation;
  _eventPtr[2UP] = &EventManager::moveUp;
  _eventPtr[2DOWN] = &EventManager::moveDown;
  _eventPtr[2LEFT] = &EventManager::moveLeft;
  _eventPtr[2RIGHT] = &EventManager::moveRight;
  _eventPtr[2BOMB] = &EventManager::bombCreation;
}

EventManager::~EventManager(void)
{
  _end = true;
  _pollEventThread->join();
}

bool		EventManager::update(void)
{ // optimisation : update call a thread pool of manageEvent() that do several update
  std::pair<EventManager::eEvent, IEntity*>		event;
  bool							pollEventUpdate = false;
  bool							timeUpdate;

  _pollEventThread->timedwait(100000000);
  if ((event = _eventQueue->tryPop()) == true)
    {
      _eventPtr[std::get<0>(event)](std::get<1>(event));
      pollEventUpdate = true;
    }
  timeUpdate = timeCheck();
  return (pollEventUpdate || timeUpdate);
}

bool		EventManager::timeCheck(void)
{
  bool		update = false;

  while (std::get<0>(_eventTime[0]) <= _gui.getElapsedTime())
    {
      _eventPtr[(std::get<1>(_eventTime[0]))->getType()](std::get<1>(_eventTime[0]));
      _eventTime.erase(_eventTime[0]);
      update = true;
    }
  return (update);
}

void		EventManager::pollEvent(void)
{
  eKey		key;

  while (!end)
    {
      key = _gui.pollEvent();
      if (key <= 1BOMB)
	_eventPtr[key](_characterMap[std::make_pair(-1, -1)]);
      else
	_eventPtr[key](_characterMap[std::make_pair(-2, -2)]);
    }
}

void		*poll_event(void *c)
{
  reinterpret_cast<EventManager *>(c)->pollEvent();
  return (NULL);
}

void		EventManager::bombCreation(IEntity *player)
{
  IEntity	*bomb;

  bomb = factory->createEntity(BOMB, player->getPosX(), player->getPosY());
  // set bomb properties with player
  _eventTime.push_back(std::make_pair(_gui.getElapsedTime() + 300000, bomb));
  std::sort(_eventTime.begin(), _eventTime.end());
  _drawQueue.push_back(bomb);
}

void		EventManager::bombDestruction(IEntity *bomb)
{
  _entityMap[std::make_pair(bomb->getPosX(), bomb->getPosY())] = NULL;
  burn(bomb->getPosX() + 1, bomb->getPosY(), bomb->getPosX() + 2, bomb->getPosY());
  burn(bomb->getPosX() - 1, bomb->getPosY(), bomb->getPosX() - 2, bomb->getPosY());
  burn(bomb->getPosX(), bomb->getPosY() + 1, bomb->getPosX(), bomb->getPosY() + 2);
  burn(bomb->getPosX(), bomb->getPosY() - 1, bomb->getPosX(), bomb->getPosY() - 2);
  burn(bomb->getPosX(), bomb->getPosY());
}

void		EventManager::moveUp(IEntity *player)
{
  double	newX;

  newX = player->getPosX() + 0.1;
  if (static_cast<int>(newX) > static_cast<int>(getPosX))
    {
      _characterMap[std::make_pair(static_cast<int>(getPosX), static_cast<int>(getPosY))] = NULL;
      _characterMap[std::make_pair(static_cast<int>(newX), static_cast<int>(getPosY))] = NULL;
    }
  player->setPosX(newX);
  _drawQueue.push_back(player);
}

void		EventManager::moveDown(IEntity *player)
{
  double	newX;

  newX = player->getPosX() - 0.1;
  if (static_cast<int>(newX) < static_cast<int>(getPosX))
    {
      _characterMap[std::make_pair(static_cast<int>(getPosX), static_cast<int>(getPosY))] = NULL;
      _characterMap[std::make_pair(static_cast<int>(newX), static_cast<int>(getPosY))] = NULL;
    }
  player->setPosX(newX);
  _drawQueue.push_back(player);
}

void		EventManager::moveLeft(IEntity *player)
{
  double	newY;

  newX = player->getPosY() + 0.1;
  if (static_cast<int>(newY) > static_cast<int>(getPosY))
    {
      _characterMap[std::make_pair(static_cast<int>(getPosX), static_cast<int>(getPosY))] = NULL;
      _characterMap[std::make_pair(static_cast<int>(getPosX), static_cast<int>(newY))] = NULL;
    }
  player->setPosY(newY);
  _drawQueue.push_back(player);
}

void		EventManager::moveRight(IEntity *player)
{
  double	newY;

  newX = player->getPosY() - 0.1;
  if (static_cast<int>(newY) < static_cast<int>(getPosY))
    {
      _characterMap[std::make_pair(static_cast<int>(getPosX), static_cast<int>(getPosY))] = NULL;
      _characterMap[std::make_pair(static_cast<int>(getPosX), static_cast<int>(newY))] = NULL;
    }
  player->setPosY(newY);
  _drawQueue.push_back(player);
}

void		EventManager::flameDestruction(IEntity *flame)
{
  _entityMap[std::make_pair(flame->getPosX(), flame->getPosY())] = NULL;
  delete flame;
}

void		EventManager::itemDrop(IEntity *item)
{
  //add properties of item to player
  _entityMap[std::make_pair(item->getPosX(), item->getPosY())] = NULL;
  delete item;
}

void		EventManager::burn(int x1, int y1, int x2, int y2)
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

void		EventManager::burn(int x, int y)
{
  if (_entityMap[std::make_pair(x, y)] == NULL ||
      _entityMap[std::make_pair(x, y)]->isBreakable() == true)
    burnEntity(x, y);
}

void		EventManager::burnEntity(int x, int y)
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

void		EventManager::flameCreation(int x, int y)
{
  IEntity	*flame;

  flame = factory->createEntity(FLAME, x, y);
  _eventTime.push_back(std::make_pair(_gui.getElapsedTime() + 100000, flame));
  std::sort(_eventTime.begin(), _eventTime.end());
  _drawQueue.push_back(flame);
}
