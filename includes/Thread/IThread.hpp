//
// IThread.hh for Plazza in /home/porres_m/Projets/Cpp/Plazza/TP
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Tue Apr 14 16:50:22 2015 Martin Porrès
// Last update Sun May 24 17:45:45 2015 Martin Porrès
//

#ifndef		_ITHREAD_HPP_
# define	_ITHREAD_HPP_

class		IThread
{
public:
  virtual ~IThread(void) {};
  virtual void	create(void *(*startRoutine)(void *), void *arg) = 0;
  virtual void	*join(void) = 0;
  virtual void	exit(void *retValue) = 0;
  virtual void	cancel(void) = 0;
};

#endif
