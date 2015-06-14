//
// EventManager.hpp for Bomberman in /home/porres_m/Projets/Cpp/Bomberman/cpp_bomberman/includes/Manager
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Sun May 24 18:14:35 2015 Martin Porrès
// Last update Sun Jun 14 21:19:23 2015 Jordan Chazottes
//

#ifndef		_EVENTMANAGER_HPP_
# define	_EVENTMANAGER_HPP_

#include	<utility>
#include	<algorithm>
#include	<iostream>
#include	"CondVar.hpp"
#include	"SafeQueue.hpp"
#include	"Factory.hpp"
#include	"Mutex.hpp"
#include	"Thread.hpp"
#include	"GDLGUI.hpp"
#include	"IEntity.hpp"
#include	"IGUI.hpp"
#include        "ThreadPool.hpp"
#include        "AInt.hpp"
#include	"eKey.hpp"
#include	"SoundManager.hpp"
#include	"Settings.hpp"

template <typename T>
class IGUI;

template <typename T>
class AInt;

template <typename T>
class		EventManager
{
public:
  enum	eEvent
    {
      FLAMEDESTRUCTION = 100,
      BOMBCREATION = 101,
      BOMBDESTRUCTION = 102,
      INCREASEBOMBSTOCK = 103,
      UP = 104,
      DOWN = 105,
      LEFT = 106,
      RIGHT = 107,
      MUTE = 108
    };
  EventManager(IGUI<T> &gui, ISafeQueue<IEntity<T> *> &drawQueue, std::map<std::pair<int, int>,
	       IEntity<T> *> &entityMap, std::map<std::pair<int, int>, IEntity<T> *> &characterMap,
	       Factory<T> &factory, ICondVar &AICondVar, SoundManager &sM, Settings &settings);
  ~EventManager(void);
  bool		update(void);
  bool		timeCheck(void);
  void		pollEvent(void);
  void		bombCreation(IEntity<T> *player);
  void		bombDestruction(IEntity<T> *bomb);
  void		moveUp(IEntity<T> *player);
  void		moveDown(IEntity<T> *player);
  void		moveLeft(IEntity<T> *player);
  void		moveRight(IEntity<T> *player);
  void		flameDestruction(IEntity<T> *flame);
  void		increaseBombStock(IEntity<T> *player);
  void		itemDrop(IEntity<T> *player, IEntity<T> *item);
  void		burn(int bombX, int bombY, int toX, int toY, double time, int bombRadius);
  void		burnEntity(int x, int y, double time);
  void		flameCreation(int x, int y, double time, bool drop);
  bool		isEnd() const;
  void		mute(IEntity<T> *player);
  bool		collider(IEntity<T> *p, double toX, double toY);
  void		generateItem(int x, int y);
  void		itemBombNumber(IEntity<T> *player);
  void		itemSpeed(IEntity<T> *player);
  void		itemRadius(IEntity<T> *player);
  void		init();
private:
  IGUI<T>							&_gui;
  ISafeQueue<IEntity<T> *>					&_drawQueue;
  ISafeQueue<std::pair<EventManager<T>::eEvent, IEntity<T> *> >	*_eventQueue;
  ICondVar							*_eventCondVar;
  IThread							*_pollEventThread;
  Mutex								_eventMutex;
  std::vector<std::pair<int, IEntity<T> *> >			_eventTime;
  typedef void (EventManager<T>::*fonc)(IEntity<T> *);
  std::map<EventManager<T>::eEvent, fonc>			_eventPtr;
  std::map<std::pair<int, int>, IEntity<T> *>			&_entityMap;
  std::map<std::pair<int, int>, IEntity<T> *>			&_characterMap;
  std::map<eEntityType, EventManager<T>::eEvent>		_timeMap;
  std::map<eKey, EventManager<T>::eEvent>			_keyMap;
  std::map<eEntityType, fonc>					_itemPtr;
  Factory<T>							&_factory;
  IThreadPool<AInt<T>, T>					*_AIPool;
  bool								_end;
  ICondVar							&_AICondVar;
  SoundManager							&_sM;
  Settings							&_settings;
};

template <typename T>
void	*poll_event(void *c);

#include	"EventManager.tpp"

#endif
