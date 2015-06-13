//
// CondVar.cpp for Plazza in /home/porres_m/Projets/Cpp/Plazza/TP/ex7
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Mon Apr 20 17:35:03 2015 Martin Porrès
// Last update Sat Jun 13 12:56:01 2015 Mathieu Bourmaud
//

#include	"CondVar.hpp"

CondVar::CondVar(Mutex &_mutex) : mutex(_mutex)
{
  if (pthread_cond_init(&cond, NULL) != 0)
    throw std::runtime_error("Conditional variable initialization has failed");
}

CondVar::~CondVar(void)
{
  if (pthread_cond_destroy(&cond) != 0)
    throw std::runtime_error("Conditional variable destruction has failed");
}

void		CondVar::wait(void)
{
  if (pthread_cond_wait(&cond, mutex.getMutex()) != 0)
    throw std::runtime_error("Conditional variable wait has failed");
}

void		CondVar::timedwait(long time)
{
  struct timespec	ts;

  clock_gettime(CLOCK_REALTIME, &ts);
  ts.tv_sec += 0;
  ts.tv_nsec += time;
  pthread_cond_timedwait(&cond, mutex.getMutex(), &ts);
}

void		CondVar::signal(void)
{
  if (pthread_cond_signal(&cond) != 0)
    throw std::runtime_error("Conditional variable signal has failed");
}

void		CondVar::broadcast(void)
{
  if (pthread_cond_broadcast(&cond) != 0)
    throw std::runtime_error("Conditional variable broadcast has failed");
}
