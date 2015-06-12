template <typename T>
Core<T>::Core(void)
{
  _lua.mapGenerate(25, 25);
  _lua.playerMapGenerate(5);
  _entityMap = _lua.getMap();
  _characterMap = _lua.getPMap();
  _drawQueue = new SafeQueue<IEntity<T> *>();
  _gui = new GDLGUI<T>(*_drawQueue, _entityMap, _characterMap);
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
    {
      if (_eventManager->update())
	_gui->draw();
    }
}

template <typename T>
MenuManager<T>	Core<T>::getMenuManager(void) const
{
  return (*_menuManager);
}
