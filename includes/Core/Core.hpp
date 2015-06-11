//
// Core.hpp for Bomberman in /home/porres_m/Projets/Cpp/Bomberman/cpp_bomberman/includes/Core
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Sun May 24 18:03:35 2015 Martin Porrès
// Last update Thu Jun 11 13:30:20 2015 Mathieu Bourmaud
//

#ifndef		_CORE_HPP_
# define	_CORE_HPP_

#include	"SafeQueue.hpp"
#include	"GDLGUI.hpp"
#include	"Factory.hpp"
#include	"EventManager.hpp"
#include	"MapGen.hpp"
#include	"MenuManager.hpp"

template <typename T>
class		Core
{
public:
  Core<T>(void);
  ~Core<T>(void);

  void		gameLoop(void);
  void		signalDraw(void);

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

#include	"Core.tpp"

#endif
