//
// EventManger.hpp for Bomberman in /home/porres_m/Projets/Cpp/Bomberman/cpp_bomberman/includes/Manager
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Sun May 24 18:14:35 2015 Martin Porrès
// Last update Wed May 27 16:49:14 2015 Martin Porrès
//

#ifndef		_EVENTMANAGER_HPP_
# define	_EVENTMANAGER_HPP_

typedef void (EventManger::*Func)(IEntity *);

class		EventManger
{
public:
    enum	eEvent
  {
    WALLDESTRUCTION,
    BOMBCREATION,
    BOMBDESTRUCTION,
    UP,
    DOWN,
    LEFT,
    RIGHT,
    FLAMEDESTRUCTION,
    ITEMDROP,
  }
  EventManger(ISafeQueue<IEntity *> &drawQueue);
  ~EventManger(void);
  bool		update(void);
  bool		timeCheck(void);
  void		pollEvent(void);
  void		wallDestruction(IEntity *wall);
  void		bombCreation(IEntity *player);
  void		bombDestruction(IEntity *bomb);
  void		moveUp(IEntity *player);
  void		moveDown(IEntity *player);
  void		moveLeft(IEntity *player);
  void		moveRight(IEntity *player);
  void		flameDestruction(IEntity *flame);
  void		itemDrop(IEntity *item);
private:
  IGUI								&_gui;
  ISafeQueue<IEntity *>						&_drawQueue;
  ISafeQueue<std::make_pair<EventManger::eEvent, IEntity*> >	_enventQueue;
  ICondVar							_eventCondVar;
  IThread							_pollEventThread;
  std::vector<int>						_enventTime;
  std::map<EventManager::eEvent, Func>				_eventPtr;
  bool								_end;
};

void	*poll_event(void *c);

#endif
