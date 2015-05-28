//
// EventManager.cpp for Bomberman in /home/porres_m/Projets/Cpp/Bomberman/cpp_bomberman/sources/Manager
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Sun May 24 18:13:31 2015 Martin Porrès
// Last update Thu May 28 17:38:21 2015 Martin Porrès
//

#include	"EventManager.hpp"

EventManager::EventManager(IGUI &gui, ISafeQueue<IEntity *> &drawQueue) : _drawQueue(drawQueue), _gui(gui)
{
  _end = false;
  _pollEventThread()->create(&poll_event);
  _eventPtr[WALLDESTRUCTION] = &EventManager::wallDestruction;
  _eventPtr[BOMBCREATION] = &EventManager::bombCreation;
  _eventPtr[BOMBDESTRUCTION] = &EventManager::bombDestruction;
  _eventPtr[UP] = &EventManager::moveUp;
  _eventPtr[DOWN] = &EventManager::moveDown;
  _eventPtr[LEFT] = &EventManager::moveLeft;
  _eventPtr[RIGHT] = &EventManager::moveRight;
  _eventPtr[FLAMEDESTRUCTION] = &EventManager::flameDestruction;
  _eventPtr[ITEMDROP] = &EventManager::itemDrop;
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

  while (_eventTime[0] <= getElapsedTime())
    {
      _eventPtr(_eventTime[0]);
      _eventTime.erase(_eventTime[0]);
      update = true;
    }
  return (update);
}

void		EventManager::pollEvent(void)
{
  while (!end)
    {
      _gui.pollEvent();
      // parse event
    }
}

void		*poll_event(void *c)
{
  reinterpret_cast<EventManager *>(c)->pollEvent();
  return (NULL);
}

void		EventManager::wallDestruction(IEntity *wall)
{ //useless ???
  delete wall;
}

void		EventManager::bombCreation(IEntity *player)
{
  IEntity	*bomb;

  // bomb = factory->clone(BOMB);
  // set bomb properties with player
  // push timer in vector
}

void		EventManager::bombDestruction(IEntity *bomb)
{
  delete bomb;
}

void		EventManager::moveUp(IEntity *player)
{
  //player.setpos(...);
}

void		EventManager::moveDown(IEntity *player)
{
  //player.setpos(...);
}

void		EventManager::moveLeft(IEntity *player)
{
  //player.setpos(...);
}

void		EventManager::moveRight(IEntity *player)
{
  //player.setpos(...);
}

void		EventManager::flameDestruction(IEntity *flame)
{
  delete flame;
}

void		EventManager::itemDrop(IEntity *item)
{
  //add properties of item to player
  delete item;
}
