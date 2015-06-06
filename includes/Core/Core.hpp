//
// Core.hpp for Bomberman in /home/porres_m/Projets/Cpp/Bomberman/cpp_bomberman/includes/Core
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Sun May 24 18:03:35 2015 Martin Porrès
// Last update Fri Jun  5 12:23:45 2015 Martin Porrès
//

#ifndef		_CORE_HPP_
# define	_CORE_HPP_

#include	"ISafeQueue.hpp"
#include	"IGUI.hpp"
#include	"Factory.hpp"
#include	"EventManager.hpp"

template <class T>
class		Core
{
public:
  Core<T>(void);
  ~Core<T>(void);
  void		gameLoop(void);
  void		signalDraw(void);
private:
  Factory<T>						_factory;
  IGUI<T>						*_gui;
  EventManager<T>					*_eventManager;
  ISafeQueue<IEntity<T> *>				_drawQueue;
  ICondVar						_drawCondVar;
  std::map<std::pair<int, int>, IEntity<T> *>		_entityMap;
  std::map<std::pair<int, int>, IEntity<T> *>		_characterMap;
};

template <class T>
Core<T>::Core(void)
{
  //generate map / load map
  _gui = new GDLGUI(&_drawQueue, &_drawCondVar, &_entityMap, &_characterMap);
  _eventManager = new EventManager(&_gui, &_drawQueue, &_entityMap, &_characterMap, &_factory);
}

template <class T>
Core<T>::~Core(void)
{
  delete _eventManager;
  delete _gui;
}

template <class T>
void		Core<T>::gameLoop(void)
{
  while(true) // while game is running
    {
      if (_eventManager.update())
	{
	  signalDraw();
	  _gui.draw();
	}
    }
}

template <class T>
void		Core<T>::signalDraw(void)
{
  _drawCondVar.signal();
}

#endif
