template <typename T>
Core<T>::Core(void)
{
  _entityMap = _lua.mapGenerate(10, 10);
  _characterMap = _lua.playerMapGenerate(5);
  _drawQueue = new SafeQueue<IEntity<T> *>();
  _drawCondVar = new CondVar(_drawMutex);
  _gui = new GDLGUI<T>(*_drawQueue, *_drawCondVar, _entityMap, _characterMap);
  _eventManager = new EventManager<T>(*_gui, *_drawQueue, _entityMap, _characterMap, _factory);
  _menuManager = new MenuManager<T>(*_gui, _settings);
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

template <typename T>
MenuManager<T>	Core<T>::getMenuManager(void) const
{
  return (*_menuManager);
}
