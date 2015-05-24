//
// ScopedLock.hh for Plazza in /home/porres_m/Projets/Cpp/Plazza/TP
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Thu Apr 16 18:17:54 2015 Martin Porrès
// Last update Sun May 24 17:49:50 2015 Martin Porrès
//

#ifndef		_SCOPEDLOCK_HPP_
# define	_SCOPEDLOCK_HPP_

#include	"Mutex.hpp"
#include	"IScopedLock.hpp"

class		ScopedLock : public IScopedLock
{
public:
  explicit ScopedLock(Mutex &_mutex);
  ~ScopedLock(void);
private:
  Mutex		&mutex;
};

#endif
