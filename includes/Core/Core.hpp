//
// Core.hpp for Bomberman in /home/porres_m/Projets/Cpp/Bomberman/cpp_bomberman/includes/Core
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Sun May 24 18:03:35 2015 Martin Porrès
// Last update Thu Jun  4 11:42:50 2015 Martin Porrès
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
  Core<T>(IGUI<T> &gui);
  ~Core<T>(void);
  void		gameLoop(void);
  void		signalDraw(void);
private:
  Factory<T>						_factory;
  EventManager<T>					_eventManager;
  IGUI<T>						&_gui;
  ISafeQueue<IEntity<T> *>				_drawQueue;
  ICondVar						_drawCondVar;
  std::map<std::pair<int, int>, IEntity<T> *>		_entityMap;
  std::map<std::pair<int, int>, IEntity<T> *>		_characterMap;
};

template <class T>
Core<T>::Core(IGUI<T> &gui) : _gui(&gui)
{
  //generate map / load map
}

template <class T>
Core<T>::~Core(void)
{

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
