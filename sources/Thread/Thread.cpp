//
// Thread.cpp for Plazza in /home/porres_m/Projets/Cpp/Plazza/TP
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Tue Apr 14 17:34:34 2015 Martin Porrès
// Last update Sun Jun 14 17:23:15 2015 Martin Porrès
//

#include	"Thread.hpp"

Thread::Thread(void) : isRunning(false)
{

}

Thread::~Thread(void)
{
  if (isRunning)
    if (pthread_join(thread, NULL) != 0)
      throw std::runtime_error("Thread join has failed");
}

void		Thread::create(void *(*startRoutine)(void *), void* arg)
{
  if (isRunning)
    throw std::runtime_error("Thread already used");
  else
    if (pthread_create(&thread, NULL, startRoutine, arg) != 0)
      throw std::runtime_error("Thread creation has failed");
  isRunning = true;
}

void		*Thread::join()
{
  void		*ret;

  ret = NULL;
  if (isRunning)
    {
      if (pthread_join(thread, &ret) != 0)
	throw std::runtime_error("Thread join has failed");
    }
  else
    throw std::runtime_error("Thread already joined");
  isRunning = false;
  return (ret);
}

void		Thread::exit(void *retValue)
{
  pthread_exit(retValue);
  isRunning = false;
}

void		Thread::cancel(void)
{
  pthread_cancel(thread);
  isRunning = false;
}
