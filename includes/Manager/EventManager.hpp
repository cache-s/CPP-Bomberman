//
// EventManger.hpp for Bomberman in /home/porres_m/Projets/Cpp/Bomberman/cpp_bomberman/includes/Manager
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Sun May 24 18:14:35 2015 Martin Porrès
// Last update Tue Jun  2 18:15:54 2015 Martin Porrès
//

#ifndef		_EVENTMANAGER_HPP_
# define	_EVENTMANAGER_HPP_

typedef void (EventManger::*Func)(IEntity *);

enum		eKey
  {
    1UP = 200,
    1DOWN = 201,
    1LEFT = 202,
    1RIGHT = 203,
    1BOMB = 204,
    2UP = 205,
    2DOWN = 206,
    2LEFT = 207,
    2RIGHT = 208,
    2BOMB = 209
  };

class		EventManger
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
  EventManger(ISafeQueue<IEntity *> &drawQueue);
  ~EventManger(void);
  bool		update(void);
  bool		timeCheck(void);
  void		pollEvent(void);
  void		bombCreation(IEntity *player);
  void		bombDestruction(IEntity *bomb);
  void		moveUp(IEntity *player);
  void		moveDown(IEntity *player);
  void		moveLeft(IEntity *player);
  void		moveRight(IEntity *player);
  void		flameDestruction(IEntity *flame);
  void		itemDrop(IEntity *item);
  void		burn(int x1, int y1, int x2, int y2);
  void		burn(int x, int y);
private:
  IGUI							&_gui;
  ISafeQueue<IEntity *>					&_drawQueue;
  ISafeQueue<std::pair<EventManger::eEvent, IEntity*> >	_enventQueue;
  ICondVar						_eventCondVar;
  IThread						_pollEventThread;
  std::vector<std::pair<int, IEntity *> >		_enventTime;
  std::map<EventManager::eEvent, Func>			_eventPtr;
  std::map<std::pair<int x, int y>, IEntity *entity>	&_entityMap;
  std::map<std::pair<int x, int y>, IEntity *character>	&_characterMap;
  bool							_end;
};

void	*poll_event(void *c);

#endif
