//
// EventManager.cpp for Bomberman in /home/porres_m/Projets/Cpp/Bomberman/cpp_bomberman/sources/Manager
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Sun May 24 18:13:31 2015 Martin Porrès
// Last update Sun May 24 18:59:02 2015 Martin Porrès
//

#include	"EventManager.hpp"

EventManager::EventManager(ISafeQueue<IEntity *> &drawQueue) : _drawQueue(drawQueue)
{
  // thread_join poll event
}

EventManager::~EventManager(void)
{
  // thread_destroy
}

void		EventManager::update(void)
{
  // wait then call manageEvent()
}

void		EventManager::wait(void)
{
  // timedwait event
}

void		EventManager::manageEvent(void)
{ // optimisation : thread pool of manageEvent()
  // parse and treats event
}

void		EventManager::pollEvent(void)
{
  // whule(true)...
}
