//
// EventManger.hpp for Bomberman in /home/porres_m/Projets/Cpp/Bomberman/cpp_bomberman/includes/Manager
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Sun May 24 18:14:35 2015 Martin Porrès
// Last update Thu Jun  4 11:45:46 2015 Martin Porrès
//

#ifndef		_EVENTMANAGER_HPP_
# define	_EVENTMANAGER_HPP_

#include	<utility>
#include	<algorithm>
#include	<iostream>
#include	"ICondVar.hpp"
#include	"ISafeQueue.hpp"
#include	"Factory.hpp"
#include	"IThread.hpp"
#include	"IGUI.hpp"
#include	"IEntity.hpp"

enum		eKey
  {
    UP1 = 200,
    DOWN1 = 201,
    LEFT1 = 202,
    RIGHT1 = 203,
    BOMB1 = 204,
    UP2 = 205,
    DOWN2 = 206,
    LEFT2 = 207,
    RIGHT2 = 208,
    BOMB2 = 209
  };

template <class T>
class		EventManager
{
public:
  enum	eEvent
    {
      BOMBCREATION = 100,
      UP = 101,
      DOWN = 102,
      LEFT = 103,
      RIGHT = 104,
      ITEMDROP = 105
    };
  EventManager(IGUI<T> &gui, ISafeQueue<IEntity<T> *> &drawQueue, std::map<std::pair<int, int>,
	       IEntity<T> *> &entityMap, std::map<std::pair<int, int>, IEntity<T> *> &characterMap,
	       Factory<T> &factory);
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
  void		itemDrop(IEntity<T> *item);
  void		burn(int x1, int y1, int x2, int y2);
  void		burn(int x, int y);
  void		burnEntity(int x, int y);
  void		flameCreation(int x, int y);
private:
  IGUI<T>							&_gui;
  ISafeQueue<IEntity<T> *>					&_drawQueue;
  ISafeQueue<std::pair<EventManager<T>::eEvent, IEntity<T> *> >	_eventQueue;
  ICondVar							_eventCondVar;
  IThread							_pollEventThread;
  std::vector<std::pair<int, IEntity<T> *> >			_eventTime;
  typedef void (EventManager<T>::*Func)();
  std::map<EventManager<T>::eEvent, Func>			_eventPtr;
  std::map<std::pair<int, int>, IEntity<T> *>			&_entityMap;
  std::map<std::pair<int, int>, IEntity<T> *>			&_characterMap;
  Factory<T>							&_factory;
  bool								_end;
};

void	*poll_event(void *c);

template <class T>
EventManager<T>::EventManager(IGUI<T> &gui, ISafeQueue<IEntity<T> *> &drawQueue,
			      std::map<std::pair<int, int>, IEntity<T> *> &entityMap,
			      std::map<std::pair<int, int>, IEntity<T> *> &characterMap,
			      Factory<T> &factory) :
  _drawQueue(drawQueue),
  _gui(gui),
  _entityMap(entityMap),
  _characterMap(characterMap),
  _factory(factory)
{
  _end = false;
  _pollEventThread().create(&poll_event);
  _eventPtr[EventManager<T>::BOMBCREATION] = &EventManager<T>::bombCreation;
  _eventPtr[EventManager<T>::UP] = &EventManager<T>::moveUp;
  _eventPtr[EventManager<T>::DOWN] = &EventManager<T>::moveDown;
  _eventPtr[EventManager<T>::LEFT] = &EventManager<T>::moveLeft;
  _eventPtr[EventManager<T>::RIGHT] = &EventManager<T>::moveRight;
  _eventPtr[EventManager<T>::ITEMDROP] = &EventManager<T>::itemDrop;
  _eventPtr[BOMB] = &EventManager<T>::bombDestruction;
  _eventPtr[FLAME] = &EventManager<T>::flameDestruction;
  _eventPtr[UP1] = &EventManager<T>::moveUp;
  _eventPtr[DOWN1] = &EventManager<T>::moveDown;
  _eventPtr[LEFT1] = &EventManager<T>::moveLeft;
  _eventPtr[RIGHT1] = &EventManager<T>::moveRight;
  _eventPtr[BOMB1] = &EventManager<T>::bombCreation;
  _eventPtr[UP2] = &EventManager<T>::moveUp;
  _eventPtr[DOWN2] = &EventManager<T>::moveDown;
  _eventPtr[LEFT2] = &EventManager<T>::moveLeft;
  _eventPtr[RIGHT2] = &EventManager<T>::moveRight;
  _eventPtr[BOMB2] = &EventManager<T>::bombCreation;
}

template <class T>
EventManager<T>::~EventManager(void)
{
  _end = true;
  _pollEventThread.join();
}

template <class T>
bool		EventManager<T>::update(void)
{ // optimisation : update call a thread pool of manageEvent() that do several update
  std::pair<EventManager<T>::eEvent, IEntity<T>*>		event;
  bool							pollEventUpdate = false;
  bool							timeUpdate;

  _eventCondVar.timedwait(100000000);
  if ((event = _eventQueue->tryPop()) == true)
    {
      _eventPtr[std::get<0>(event)](std::get<1>(event));
      pollEventUpdate = true;
    }
  timeUpdate = timeCheck();
  return (pollEventUpdate || timeUpdate);
}

template <class T>
bool		EventManager<T>::timeCheck(void)
{
  bool		update = false;

  while (std::get<0>(_eventTime[0]) <= _gui.getElapsedTime())
    { // signal instead of call
      _eventPtr[(std::get<1>(_eventTime[0]))->getType()](std::get<1>(_eventTime[0]));
      _eventTime.erase(_eventTime[0]);
      update = true;
    }
  return (update);
}

template <class T>
void		*poll_event(void *c)
{
  reinterpret_cast<EventManager<T> *>(c)->pollEvent();
  return (NULL);
}

template <class T>
void		EventManager<T>::pollEvent(void)
{
  eKey		key;

  while (!_end)
    {
      key = _gui.pollEvent();
      if (key <= BOMB1) // signal instead of call
	_eventPtr[key](_characterMap[std::make_pair(-1, -1)]);
      else
	_eventPtr[key](_characterMap[std::make_pair(-2, -2)]);
    }
}

template <class T>
void		EventManager<T>::bombCreation(IEntity<T> *player)
{
  IEntity<T>	*bomb;

  bomb = _factory.createEntity(BOMB, player->getPosX(), player->getPosY());
  // set bomb properties with player
  _eventTime.push_back(std::make_pair(_gui.getElapsedTime() + 300000, bomb));
  std::sort(_eventTime.begin(), _eventTime.end());
  _drawQueue.push_back(bomb);
}

template <class T>
void		EventManager<T>::bombDestruction(IEntity<T> *bomb)
{
  _entityMap[std::make_pair(bomb->getPosX(), bomb->getPosY())] = NULL;
  burn(bomb->getPosX() + 1, bomb->getPosY(), bomb->getPosX() + 2, bomb->getPosY());
  burn(bomb->getPosX() - 1, bomb->getPosY(), bomb->getPosX() - 2, bomb->getPosY());
  burn(bomb->getPosX(), bomb->getPosY() + 1, bomb->getPosX(), bomb->getPosY() + 2);
  burn(bomb->getPosX(), bomb->getPosY() - 1, bomb->getPosX(), bomb->getPosY() - 2);
  burn(bomb->getPosX(), bomb->getPosY());
}

template <class T>
void		EventManager<T>::moveUp(IEntity<T> *player)
{
  double	newX;

  newX = player->getPosX() + 0.1;
  if (static_cast<int>(newX) > static_cast<int>(player->getPosX()))
    {
      _characterMap[std::make_pair(static_cast<int>(player->getPosX()), static_cast<int>(player->getPosY()))] = NULL;
      _characterMap[std::make_pair(static_cast<int>(newX), static_cast<int>(player->getPosY()))] = NULL;
    }
  player->setPosX(newX);
  _drawQueue.push_back(player);
}

template <class T>
void		EventManager<T>::moveDown(IEntity<T> *player)
{
  double	newX;

  newX = player->getPosX() - 0.1;
  if (static_cast<int>(newX) < static_cast<int>(player->getPosX()))
    {
      _characterMap[std::make_pair(static_cast<int>(player->getPosX()), static_cast<int>(player->getPosY()))] = NULL;
      _characterMap[std::make_pair(static_cast<int>(newX), static_cast<int>(player->getPosY()))] = NULL;
    }
  player->setPosX(newX);
  _drawQueue.push_back(player);
}

template <class T>
void		EventManager<T>::moveLeft(IEntity<T> *player)
{
  double	newY;

  newY = player->getPosY() + 0.1;
  if (static_cast<int>(newY) > static_cast<int>(player->getPosY()))
    {
      _characterMap[std::make_pair(static_cast<int>(player->getPosX()), static_cast<int>(player->getPosY()))] = NULL;
      _characterMap[std::make_pair(static_cast<int>(player->getPosX()), static_cast<int>(newY))] = NULL;
    }
  player->setPosY(newY);
  _drawQueue.push_back(player);
}

template <class T>
void		EventManager<T>::moveRight(IEntity<T> *player)
{
  double	newY;

  newY = player->getPosY() - 0.1;
  if (static_cast<int>(newY) < static_cast<int>(player->getPosY()))
    {
      _characterMap[std::make_pair(static_cast<int>(player->getPosX()), static_cast<int>(player->getPosY()))] = NULL;
      _characterMap[std::make_pair(static_cast<int>(player->getPosX()), static_cast<int>(newY))] = NULL;
    }
  player->setPosY(newY);
  _drawQueue.push_back(player);
}

template <class T>
void		EventManager<T>::flameDestruction(IEntity<T> *flame)
{
  _entityMap[std::make_pair(flame->getPosX(), flame->getPosY())] = NULL;
  delete flame;
}

template <class T>
void		EventManager<T>::itemDrop(IEntity<T> *item)
{
  //add properties of item to player
  _entityMap[std::make_pair(item->getPosX(), item->getPosY())] = NULL;
  delete item;
}

template <class T>
void		EventManager<T>::burn(int x1, int y1, int x2, int y2)
{
  if (_entityMap[std::make_pair(x1, y1)] == NULL ||
      _entityMap[std::make_pair(x1, y1)]->isBreakable() == true)
    {
      burnEntity(x1, y1);
      if (_entityMap[std::make_pair(x2, y2)] == NULL ||
	  _entityMap[std::make_pair(x2, y2)]->isBreakable() == true)
	burnEntity(x2, y2);
    }
}

template <class T>
void		EventManager<T>::burn(int x, int y)
{
  if (_entityMap[std::make_pair(x, y)] == NULL ||
      _entityMap[std::make_pair(x, y)]->isBreakable() == true)
    burnEntity(x, y);
}

template <class T>
void		EventManager<T>::burnEntity(int x, int y)
{
  if (_entityMap[std::make_pair(x, y)] != NULL)
    {
      delete _entityMap[std::make_pair(x, y)];
      _entityMap[std::make_pair(x, y)] = NULL;
    }
  if (_characterMap[std::make_pair(x, y)] != NULL)
    {
      delete _characterMap[std::make_pair(x, y)];
      _characterMap[std::make_pair(x, y)] = NULL;
    }
  flameCreation(x, y);
}

template <class T>
void		EventManager<T>::flameCreation(int x, int y)
{
  IEntity<T>	*flame;

  flame = _factory.createEntity(FLAME, x, y);
  _eventTime.push_back(std::make_pair(_gui.getElapsedTime() + 100000, flame));
  std::sort(_eventTime.begin(), _eventTime.end());
  _drawQueue.push_back(flame);
}

#endif
