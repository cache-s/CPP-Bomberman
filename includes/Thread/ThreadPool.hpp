//
// ThreadPool.hh for Plazza in /home/porres_m/Projets/Cpp/Plazza/TP
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Tue Apr 21 17:03:24 2015 Martin Porrès
// Last update Sun May 24 17:48:20 2015 Martin Porrès
//

#ifndef		_THREADPOOL_HPP_
# define	_THREADPOOL_HPP_

#include	<iostream>
#include	<vector>
#include	"Thread.hpp"
#include	"Mutex.hpp"
#include	"Task.hpp"
#include	"SafeQueue.hpp"
#include	"CondVar.hpp"
#include	"IThreadPool.hpp"

template <typename T>
class ThreadPool : public IThreadPool<T>
{
public:
  explicit ThreadPool(int nbThread) : condVarPool(mutexPool)
  {
    int	i;

    i = 0;
    while (i < nbThread)
      {
	pool.push_back(new Thread());
	tasks.push_back(new Task(&queue, &mutexPool, &condVarPool, i));
	(pool.back())->create(&thread_loop, reinterpret_cast<void *>(tasks.back())); 
	i++;
      }
  }

  ~ThreadPool()
  {
    while (!pool.empty())
      {
    	(pool.back())->join();
    	delete pool.back();
    	pool.pop_back();
    	delete tasks.back();
    	tasks.pop_back();
      }
  }

  bool			addTask(T *order)
  {
    try
      {
	queue.push(order);
      }
    catch (const std::runtime_error &e)
      {
	std::cerr << e.what() << std::endl;
	delete order;
	return (false);
      }
    condVarPool.signal();
    return (true);
  }

  void			setFinished(void)
  {
    queue.setFinished();
    condVarPool.broadcast();
  }

private:
  std::vector<Thread *>	pool;
  std::vector<Task *>	tasks;
  SafeQueue<T *>	queue;
  Mutex			mutexPool;
  CondVar		condVarPool;
};

#endif
