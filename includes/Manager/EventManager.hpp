//
// EventManger.hpp for Bomberman in /home/porres_m/Projets/Cpp/Bomberman/cpp_bomberman/includes/Manager
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Sun May 24 18:14:35 2015 Martin Porrès
// Last update Mon May 25 18:28:39 2015 Martin Porrès
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
  void		update(void);
  void		pollEvent(void);
  void		wallDestruction(IEntity *);
  void		bombCreation(IEntity *);
  void		bombDestruction(IEntity *);
  void		moveUp(IEntity *);
  void		moveDown(IEntity *);
  void		moveLeft(IEntity *);
  void		moveRight(IEntity *);
  void		flameDestruction(IEntity *);
  void		itemDrop(IEntity *);
private:
  ISafeQueue<IEntity *>						&_drawQueue;
  ISafeQueue<std::make_pair<EventManger::eEvent, IEntity*> >	_enventQueue;
  ICondVar							_eventCondVar;
  IThread							_pollEventThread;
  std::vector<int>						_enventTime;
  std::map<EventManager::eEvent, Func>				_eventPtr;
};

void	*poll_event(void *c);

#endif
