//
// Task.cpp for Plazza in /home/porres_m/Projets/Cpp/Plazza/TP
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Thu Apr 23 10:21:10 2015 Martin Porrès
// Last update Sun May 24 18:20:52 2015 Martin Porrès
//

#include	"Task.hpp"

Task::Task(SafeQueue<Mutex */* Replace type*/> &_queue, Mutex &_mutexPool, CondVar &_condVar, int _id) :
  queue(_queue),
  mutexPool(_mutexPool),
  condVar(_condVar),
  id(_id)
{

}

Task::~Task(void)
{

}

void		Task::threadLoop(void)
{
  Mutex		*/* Replace type*/task;
  bool		end;

  end = false;
  while (!end || !queue.isEmpty())
    {
      if (!(end = queue.isFinished()))
	{
	  mutexPool.lock();
	  if (!queue.tryPop(&task))
	    {
	      condVar.wait();
	      mutexPool.unlock();
	    }
	  else
	    {
	      mutexPool.unlock();
	      if (!queue.isEmpty())
		condVar.signal();
	      std::cout << "id : " << id << " Task" << std::endl;;
	      delete task;
	    }
	}
    }
}

void		*thread_loop(void *c)
{
  reinterpret_cast<Task *>(c)->threadLoop();
  return (NULL);
}
