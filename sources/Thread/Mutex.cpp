//
// Mutex.cpp for Plazza in /home/porres_m/Projets/Cpp/Plazza/TP
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Tue Apr 14 11:17:54 2015 Martin Porrès
// Last update Sun May 24 17:12:24 2015 Martin Porrès
//

#include	"Mutex.hpp"

Mutex::Mutex(void)
{
  if (pthread_mutex_init(&mutex, NULL) != 0)
    throw std::runtime_error("Mutex initialization has failed");
}

Mutex::~Mutex(void)
{
  if (pthread_mutex_destroy(&mutex) != 0)
    throw std::runtime_error("Mutex destruction has failed");
}

void		Mutex::lock(void)
{
  if (pthread_mutex_lock(&mutex) != 0)
    throw std::runtime_error("Mutex lock has failed");
}

void		Mutex::unlock(void)
{
  if (pthread_mutex_unlock(&mutex) != 0)
    throw std::runtime_error("Mutex unlock has failed");
}

bool		Mutex::trylock(void)
{
  if (pthread_mutex_trylock(&mutex) == 0)
    return (true);
  return (false);
}

pthread_mutex_t	*Mutex::getMutex(void)
{
  return (&mutex);
}
