//
// Thread.hh for Plazza in /home/porres_m/Projets/Cpp/Plazza/TP
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Tue Apr 14 17:11:07 2015 Martin Porrès
// Last update Sun May 24 17:47:04 2015 Martin Porrès
//

#ifndef		_THREAD_HPP_
# define	_THREAD_HPP_

#include	<pthread.h>
#include	<stdexcept>
#include	"IThread.hpp"

class		Thread : public IThread
{
public:
  Thread(void);
  ~Thread(void);
  void		create(void *(*startRoutine)(void *), void *arg);
  void		*join(void);
  void		exit(void *retValue);
  void		cancel(void);
private:
  pthread_t	thread;
  bool		isRunning;
};

#endif
