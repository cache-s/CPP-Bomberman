//
// Core.hpp for Bomberman in /home/porres_m/Projets/Cpp/Bomberman/cpp_bomberman/includes/Core
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Sun May 24 18:03:35 2015 Martin Porrès
// Last update Sun Jun 14 19:36:28 2015 Mathieu Bourmaud
//

#ifndef		_CORE_HPP_
# define	_CORE_HPP_

#include	"SafeQueue.hpp"
#include	"GDLGUI.hpp"
#include	"Factory.hpp"
#include	"EventManager.hpp"
#include	"MapGen.hpp"
#include	"MenuManager.hpp"
#include	"Settings.hpp"

template <typename T>
class		Core
{
public:
  Core<T>(void);
  ~Core<T>(void);

  void		gameLoop(void);
  void		signalDraw(void);

  //GETTERS
  MenuManager<T>	getMenuManager(void) const;

private:
  Factory<T>						_factory;
  IGUI<T>						*_gui;
  EventManager<T>					*_eventManager;
  ISafeQueue<IEntity<T> *>				*_drawQueue;
  Mutex							_drawMutex;
  ICondVar						*_drawCondVar;
  std::map<std::pair<int, int>, IEntity<T> *>		_entityMap;
  std::map<std::pair<int, int>, IEntity<T> *>		_characterMap;
  MapGen						_lua;
  MenuManager<T>					*_menuManager;
  Settings						_settings;
};

template <typename T>
Core<T>::Core(void)
{
  //generate map / load map
  _entityMap = _lua.mapGenerate(10, 10);
  _characterMap = _lua.playerMapGenerate(5);
  _drawQueue = new SafeQueue<IEntity<T> *>();
  _drawCondVar = new CondVar(_drawMutex);
  _gui = new GDLGUI<T>(*_drawQueue, *_drawCondVar, _entityMap, _characterMap);
  _eventManager = new EventManager<T>(*_gui, *_drawQueue, _entityMap, _characterMap, _factory);
  _menuManager = new MenuManager<T>(*_gui, _settings);
}

template <typename T>
Core<T>::~Core(void)
{
  delete _eventManager;
  delete _gui;
}

template <typename T>
void		Core<T>::gameLoop(void)
{
  while(!(_eventManager->isEnd())) // while game is running
    {
      if (_eventManager->update())
	{
	  signalDraw();
	  //_gui->draw();
	}
    }
}

template <typename T>
void		Core<T>::signalDraw(void)
{
  _drawCondVar->signal();
}

template <typename T>
MenuManager<T>	Core<T>::getMenuManager(void) const
{
  return (*_menuManager);
}

#endif
