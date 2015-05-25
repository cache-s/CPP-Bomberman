//
// ICondVar.hh for Plazza in /home/porres_m/Projets/Cpp/Plazza/TP/ex7
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Mon Apr 20 15:18:12 2015 Martin Porrès
// Last update Mon May 25 15:40:10 2015 Martin Porrès
//

#ifndef		_ICONDVAR_HPP_
# define	_ICONDVAR_HPP_

class		ICondVar
{
public:
  virtual ~ICondVar(void) {};
  virtual void	wait(void) = 0;
  virtual void	timedwait(long time) = 0;
  virtual void	signal(void) = 0;
  virtual void	broadcast(void) = 0;
};

#endif
