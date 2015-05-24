//
// ITask.hh for Plazza in /home/porres_m/Projets/Cpp/Plazza/ThreadPool
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Thu Apr 23 14:26:24 2015 Martin Porrès
// Last update Sun May 24 17:43:20 2015 Martin Porrès
//

#ifndef		_ITASK_HPP_
# define	_ITASK_HPP_

class		ITask
{
public:
  virtual ~ITask(void) {};
  virtual void	threadLoop(void) = 0;
};

#endif
