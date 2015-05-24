//
// IMutex.hh for Plazza in /home/porres_m/Projets/Cpp/Plazza/TP
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Tue Apr 14 11:06:18 2015 Martin Porrès
// Last update Sun May 24 17:15:34 2015 Martin Porrès
//

#ifndef				_IMUTEX_HPP_
# define			_IMUTEX_HPP_

#include			<pthread.h>

class				IMutex
{
public:
  virtual ~IMutex(void) {};
  virtual void			lock(void) = 0;
  virtual void			unlock(void) = 0;
  virtual bool			trylock(void) = 0;
  virtual pthread_mutex_t	*getMutex(void) = 0;
};

#endif
