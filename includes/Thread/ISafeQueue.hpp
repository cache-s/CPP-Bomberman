//
// ISafeQueue.hh for Plazza in /home/porres_m/Projets/Cpp/Plazza/TP/ex5
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Fri Apr 17 11:05:22 2015 Martin Porrès
// Last update Sun May 24 17:26:59 2015 Martin Porrès
//

#ifndef		_ISAFEQUEUE_HPP_
# define	_ISAFEQUEUE_HPP_

template <typename T>
class		ISafeQueue
{
public:
  virtual ~ISafeQueue(void) {};
  virtual void	push(T value) = 0;
  virtual bool	tryPop(T *value) = 0;
  virtual bool	isFinished(void) = 0;
  virtual void	setFinished(void) = 0;
  virtual bool	isEmpty(void) = 0;
};

#endif
