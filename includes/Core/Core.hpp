//
// Core.hpp for Bomberman in /home/porres_m/Projets/Cpp/Bomberman/cpp_bomberman/includes/Core
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Sun May 24 18:03:35 2015 Martin Porrès
// Last update Mon Jun  8 16:19:14 2015 Mathieu Bourmaud
//

#ifndef		_CORE_HPP_
# define	_CORE_HPP_

#include	"SafeQueue.hpp"
#include	"GDLGUI.hpp"
#include	"Factory.hpp"
#include	"EventManager.hpp"
#include	"MapGen.hpp"

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
  ISafeQueue<IEntity<T> *>				*_drawQueue;
  Mutex							_drawMutex;
  ICondVar						*_drawCondVar;
  std::map<std::pair<int, int>, IEntity<T> *>		_entityMap;
  std::map<std::pair<int, int>, IEntity<T> *>		_characterMap;
  MapGen							_lua;
};

template <class T>
Core<T>::Core(void)
{
  //generate map / load map
  _entityMap = _lua.mapGenerate(10, 10);
  _drawQueue = new SafeQueue<IEntity<T> *>();
  _drawCondVar = new CondVar(_drawMutex);
  _gui = new GDLGUI<T>(*_drawQueue, *_drawCondVar, _entityMap, _characterMap);
  _eventManager = new EventManager<T>(*_gui, *_drawQueue, _entityMap, _characterMap, _factory);
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
      if (_eventManager->update())
	{
	  signalDraw();
	  _gui->draw();
	}
    }
}

template <class T>
void		Core<T>::signalDraw(void)
{
  _drawCondVar->signal();
}

#endif
