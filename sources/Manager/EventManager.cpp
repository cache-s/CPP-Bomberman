//
// EventManager.cpp for Bomberman in /home/porres_m/Projets/Cpp/Bomberman/cpp_bomberman/sources/Manager
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Sun May 24 18:13:31 2015 Martin Porrès
// Last update Mon Jun  1 18:06:24 2015 Martin Porrès
//

#include	"EventManager.hpp"

EventManager::EventManager(IGUI &gui, ISafeQueue<IEntity *> &drawQueue) : _drawQueue(drawQueue), _gui(gui)
{
  _end = false;
  _pollEventThread()->create(&poll_event);
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

  while (std::get<0>(_eventTime[0]) <= getElapsedTime())
    {
      _eventPtr[BOMBDESTRUCTION](std::get<1>(_eventTime[0])); // set event in case of entity
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

void		EventManager::bombCreation(IEntity *player)
{
  IEntity	*bomb;

  // bomb = factory->clone(BOMB);
  // set bomb properties with player
  // push timer in vector
  // push bomb in container
}

void		EventManager::bombDestruction(IEntity *bomb)
{
  delete bomb;
  // delete brkWall
  // new flame x9
  // push timer in vector
  // push flame in container
}

void		EventManager::moveUp(IEntity *player)
{
  player->setPosX(player->getPosX() + 1);
}

void		EventManager::moveDown(IEntity *player)
{
  player->setPosX(player->getPosX() - 1);
}

void		EventManager::moveLeft(IEntity *player)
{
  player->setPosY(player->getPosY() + 1);
}

void		EventManager::moveRight(IEntity *player)
{
  player->setPosY(player->getPosY() - 1);
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
