//
// EventManager.hpp for Bomberman in /home/porres_m/Projets/Cpp/Bomberman/cpp_bomberman/includes/Manager
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Sun May 24 18:14:35 2015 Martin Porrès
// Last update Sat Jun 13 17:58:15 2015 Jordan Chazottes
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

template <class T>
class IGUI;

template <class T>
class AInt;

// enum		eKey
//   {
//     UP1 = 200,
//     DOWN1 = 201,
//     LEFT1 = 202,
//     RIGHT1 = 203,
//     BOMB1 = 204,
//     UP2 = 205,
//     DOWN2 = 206,
//     LEFT2 = 207,
//     RIGHT2 = 208,
//     BOMB2 = 209,
//     QUIT = 210,
//     NONE = 211,
//   };

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
      ITEMDROP = 108
    };
  EventManager(IGUI<T> &gui, ISafeQueue<IEntity<T> *> &drawQueue, std::map<std::pair<int, int>,
	       IEntity<T> *> &entityMap, std::map<std::pair<int, int>, IEntity<T> *> &characterMap,
	       Factory<T> &factory, ICondVar &AICondVar, SoundManager &sM);
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
  void		itemDrop(IEntity<T> *item);
  void		burn(int x1, int y1, int x2, int y2, double time);
  void		burn(int x, int y, double time);
  void		burnEntity(int x, int y, double time);
  void		flameCreation(int x, int y, double time);
  bool		isEnd() const;
  bool		collider(IEntity<T> *p, IEntity<T> *obj, double toX, double toY);
private:
  IGUI<T>							&_gui;
  ISafeQueue<IEntity<T> *>					&_drawQueue;
  ISafeQueue<std::pair<EventManager<T>::eEvent, IEntity<T> *> >	*_eventQueue;
  ICondVar							*_eventCondVar;
  IThread							*_pollEventThread;
  Mutex								_eventMutex;
  std::vector<std::pair<int, IEntity<T> *> >			_eventTime;
  typedef void (EventManager<T>::*Func)(IEntity<T> *);
  std::map<EventManager<T>::eEvent, Func>			_eventPtr;
  std::map<std::pair<int, int>, IEntity<T> *>			&_entityMap;
  std::map<std::pair<int, int>, IEntity<T> *>			&_characterMap;
  std::map<eEntityType, EventManager<T>::eEvent>		_timeMap;
  std::map<eKey, EventManager<T>::eEvent>			_keyMap;
  Factory<T>							&_factory;
  IThreadPool<AInt<T>, T>					*_AIPool;
  bool								_end;
  SoundManager							&_sM;
};

template <typename T>
void	*poll_event(void *c);

#include	"EventManager.tpp"

#endif
