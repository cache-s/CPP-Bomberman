//
// Mutex.hh for Plazza in /home/porres_m/Projets/Cpp/Plazza/TP
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Tue Apr 14 11:08:37 2015 Martin Porrès
// Last update Sun May 24 17:16:00 2015 Martin Porrès
//

#ifndef			_MUTEX_HPP_
# define		_MUTEX_HPP_

#include		<pthread.h>
#include		<stdexcept>
#include		"IMutex.hpp"

class			Mutex : public IMutex
{
public:
  Mutex();
  ~Mutex();
  void			lock(void);
  void			unlock(void);
  bool			trylock(void);
  pthread_mutex_t	*getMutex(void);
private:
  pthread_mutex_t	mutex;
};

#endif
