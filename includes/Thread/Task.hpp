//
// Task.hh for Plazza in /home/porres_m/Projets/Cpp/Plazza/TP
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Thu Apr 23 10:12:47 2015 Martin Porrès
// Last update Sun May 24 17:43:53 2015 Martin Porrès
//

#ifndef		_TASK_HPP_
# define	_TASK_HPP_

#include	<iostream>
#include	"SafeQueue.hpp"
#include	"Mutex.hpp"
#include	"CondVar.hpp"
#include	"ITask.hpp"

class		Task : public ITask
{
public:
  Task(SafeQueue<Mutex */*Replace type*/> *_queue, Mutex *_mutexPool, CondVar *_condVar, int id);
  ~Task(void);
  void		threadLoop(void);
private:
  SafeQueue<Mutex */*Replace type*/>	*queue;
  Mutex			*mutexPool;
  CondVar		*condVar;
  int			id;
};

void	*thread_loop(void * c);

#endif
