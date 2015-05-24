//
// EventManger.hpp for Bomberman in /home/porres_m/Projets/Cpp/Bomberman/cpp_bomberman/includes/Manager
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Sun May 24 18:14:35 2015 Martin Porrès
// Last update Sun May 24 18:52:56 2015 Martin Porrès
//

#ifndef		_EVENTMANAGER_HPP_
# define	_EVENTMANAGER_HPP_

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
  void		wait(void);
  void		manageEvent(void);
  void		pollEvent(void)
private:
  ISafeQueue<IEntity *>						&_drawQueue;
  ISafeQueue<std::make_pair<EventManger::eEvent, IEntity*> >	_enventQueue;
  ICondVar							_eventCondVar;
  IThread							_pollEventThread;
  std::vector<int>						_enventTime;
}

#endif
