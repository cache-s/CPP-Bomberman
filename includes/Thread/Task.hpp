//
// Task.hh for Plazza in /home/porres_m/Projets/Cpp/Plazza/TP
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Thu Apr 23 10:12:47 2015 Martin Porrès
// Last update Sat Jun 13 11:01:32 2015 Martin Porrès
//

#ifndef		_TASK_HPP_
# define	_TASK_HPP_

#include	<iostream>
#include	"SafeQueue.hpp"
#include	"Mutex.hpp"
#include	"CondVar.hpp"
#include	"ITask.hpp"
#include	"AInt.hpp"

template	<typename U>
class		Task : public ITask<U>
{
public:
  Task(SafeQueue<AInt<U> *> &_queue, Mutex &_mutexPool, CondVar &_condVar, int _id);
  ~Task(void);
  void		threadLoop(void);
private:
  SafeQueue<AInt<U> *>	&queue;
  Mutex			&mutexPool;
  CondVar		&condVar;
  int			id;
};

template	<typename U>
void	*thread_loop(void *c);

template	<typename U>
Task<U>::Task(SafeQueue<AInt<U> *> &_queue, Mutex &_mutexPool, CondVar &_condVar, int _id) :
  queue(_queue),
  mutexPool(_mutexPool),
  condVar(_condVar),
  id(_id)
{

}

template	<typename U>
Task<U>::~Task(void)
{

}

template	<typename U>
void		Task<U>::threadLoop(void)
{
  AInt<U>	*bot;
  bool		end;

  end = false;
  while (!end || !queue.isEmpty())
    {
      if (!(end = queue.isFinished()))
	{
	  mutexPool.lock();
	  if (!queue.tryPop(&bot))
	    {
	      condVar.wait();
	      mutexPool.unlock();
	    }
	  else
	    {
	      mutexPool.unlock();
	      if (!queue.isEmpty())
		condVar.signal();
	      bot->move();
	    }
	}
    }
}

template	<typename U>
void		*thread_loop(void *c)
{
  reinterpret_cast<Task<U> *>(c)->threadLoop();
  return (NULL);
}

#endif
