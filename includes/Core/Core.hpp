//
// Core.hpp for Bomberman in /home/porres_m/Projets/Cpp/Bomberman/cpp_bomberman/includes/Core
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Sun May 24 18:03:35 2015 Martin Porrès
// Last update Sun May 24 18:53:05 2015 Martin Porrès
//

#ifndef		_CORE_HPP_
# define	_CORE_HPP_

#include	"ISafeQueue.hpp"

class		Core
{
public:
  Core(void);
  ~Core(void);
  void		gameLoop(void);
  void		signalDraw(void);
private:
  EnventManager		_eventManager;
  ISafeQueue<IEntity *>	_drawQueue;
  ICondVar		_drawCondVar;
  //IGUI		&_gui;
}

#endif
