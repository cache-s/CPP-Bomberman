template <typename T>
Core<T>::Core(void)
{
  _lua.mapGenerate(10, 10);
  _lua.playerMapGenerate(2);
  _entityMap = _lua.getMap();
  _characterMap = _lua.getPMap();
  _drawQueue = new SafeQueue<IEntity<T> *>();
  _gui = new GDLGUI<T>(*_drawQueue, _entityMap, _characterMap);
  _AICondVar = new CondVar(_AIMutex);
  _eventManager = new EventManager<T>(*_gui, *_drawQueue, _entityMap, _characterMap, _factory, *_AICondVar);
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
      std::cout << "COREEEEEEEEEEE" << std::endl;
      if (_eventManager->update())
	{
	  _gui->draw();
	  _AICondVar->broadcast();
	}
    }
}

template <typename T>
MenuManager<T>	Core<T>::getMenuManager(void) const
{
  return (*_menuManager);
}
