//
// IThreadPool.hh for Plazza in /home/porres_m/Projets/Cpp/Plazza/TP
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Thu Apr 23 11:48:31 2015 Martin Porrès
// Last update Fri Jun 12 23:17:37 2015 Martin Porrès
//

#ifndef		_ITHREADPOOL_HPP_
# define	_ITHREADPOOL_HPP_

template <typename T, typename U>
class		IThreadPool
{
public:
  virtual ~IThreadPool(void) {};
  virtual bool	addTask(T *order) = 0;
  virtual void	setFinished(void) = 0;
};

#endif
