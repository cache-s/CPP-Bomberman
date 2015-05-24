//
// ScopedLock.cpp for Plazza in /home/porres_m/Projets/Cpp/Plazza/TP
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Thu Apr 16 18:26:41 2015 Martin Porrès
// Last update Sun May 24 17:12:31 2015 Martin Porrès
//

#include	"ScopedLock.hpp"

ScopedLock::ScopedLock(Mutex &_mutex) : mutex(_mutex)
{
  mutex.lock();
}

ScopedLock::~ScopedLock()
{
  mutex.unlock();
}
