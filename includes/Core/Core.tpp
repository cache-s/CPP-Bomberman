//
// Core.tpp for Bomber in /home/porres_m/Projets/Cpp/Bomberman/cpp_bomberman/includes/Core
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Tue Jun  9 23:03:09 2015 Martin Porrès
// Last update Tue Jun  9 23:04:05 2015 Martin Porrès
//

template <typename T>
Core<T>::Core(void)
{
  _entityMap = _lua.mapGenerate(10, 10);
  _characterMap = _lua.playerMapGenerate(5);
  _drawQueue = new SafeQueue<IEntity<T> *>();
  _drawCondVar = new CondVar(_drawMutex);
  _gui = new GDLGUI<T>(*_drawQueue, *_drawCondVar, _entityMap, _characterMap);
  _eventManager = new EventManager<T>(*_gui, *_drawQueue, _entityMap, _characterMap, _factory);
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
  while(!(_eventManager->isEnd()))
    if (_eventManager->update())
      signalDraw();
}

template <typename T>
void		Core<T>::signalDraw(void)
{
  _drawCondVar->signal();
}
