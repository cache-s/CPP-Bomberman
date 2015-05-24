//
// CondVar.hh for Plazza in /home/porres_m/Projets/Cpp/Plazza/TP/ex7
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Mon Apr 20 17:29:51 2015 Martin Porrès
// Last update Sun May 24 17:14:00 2015 Martin Porrès
//

#ifndef			_CONDVAR_HPP_
# define		_CONDVAR_HPP_

#include		<pthread.h>
#include		<time.h>
#include		"Mutex.hpp"
#include		"ICondVar.hpp"

class			CondVar : public ICondVar
{
public:
  CondVar(Mutex &_mutex);
  ~CondVar(void);
  void			wait(void);
  void			timedwait(double time);
  void			signal(void);
  void			broadcast(void);
private:
  Mutex			&mutex;
  pthread_cond_t	cond;
};

#endif
