//
// EventManager.cpp for Bomberman in /home/porres_m/Projets/Cpp/Bomberman/cpp_bomberman/sources/Manager
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Sun May 24 18:13:31 2015 Martin Porrès
// Last update Mon May 25 18:28:32 2015 Martin Porrès
//

#include	"EventManager.hpp"

EventManager::EventManager(ISafeQueue<IEntity *> &drawQueue) : _drawQueue(drawQueue)
{
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
  _pollEventThread->exit(NULL);
}

void		EventManager::update(void)
{ // optimisation : update call a thread pool of manageEvent() that do several update
  std::make_pair<EventManager::eEvent, IEntity*>	event;

  _pollEventThread->timedwait(100000000);
  if ((event = _eventQueue->tryPop()) == true)
    _eventPtr[std::get<0>(event)](std::get<1>(event));
}

void		EventManager::pollEvent(void)
{
  // whule(true)...
}

void		*poll_event(void *c)
{
  reinterpret_cast<EventManager *>(c)->pollEvent();
  return (NULL);
}

void		EventManager::wallDestruction(IEntity *)
{

}

void		EventManager::bombCreation(IEntity *)
{

}

void		EventManager::bombDestruction(IEntity *)
{

}

void		EventManager::moveUp(IEntity *)
{

}

void		EventManager::moveDown(IEntity *)
{

}

void		EventManager::moveLeft(IEntity *)
{

}

void		EventManager::moveRight(IEntity *)
{

}

void		EventManager::flameDestruction(IEntity *)
{

}

void		EventManager::itemDrop(IEntity *)
{

}
