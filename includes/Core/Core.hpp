//
// Core.hpp for Bomberman in /home/porres_m/Projets/Cpp/Bomberman/cpp_bomberman/includes/Core
//
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
//
// Started on  Sun May 24 18:03:35 2015 Martin Porrès
// Last update Sun Jun 14 21:09:17 2015 Jordan Chazottes
//

#ifndef		_CORE_HPP_
# define	_CORE_HPP_

#include	"SafeQueue.hpp"
#include	"GDLGUI.hpp"
#include	"Factory.hpp"
#include	"EventManager.hpp"
#include	"MapGen.hpp"
#include	"MenuManager.hpp"
#include	"SoundManager.hpp"

template <typename T>
class		Core
{
public:
  Core<T>(void);
  ~Core<T>(void);

  void		loadGame();
  eMenuEvent	loadMenu();
  void		gameLoop(void);
  void		signalDraw(void);

  MenuManager<T>	getMenuManager(void) const;

private:
  Factory<T>						_factory;
  IGUI<T>						*_gui;
  EventManager<T>					*_eventManager;
  ISafeQueue<IEntity<T> *>				*_drawQueue;
  Mutex							_drawMutex;
  std::map<std::pair<int, int>, IEntity<T> *>		_entityMap;
  std::map<std::pair<int, int>, IEntity<T> *>		_characterMap;
  MapGen<T>						_lua;
  SoundManager						*_soundManager;
  MenuManager<T>					*_menuManager;
  Settings						_settings;
  Mutex                                                 _AIMutex;
  ICondVar                                              *_AICondVar;
};

#include	"Core.tpp"

#endif
