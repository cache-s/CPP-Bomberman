template <typename T>
Core<T>::Core(void)
{
  _drawQueue = new SafeQueue<IEntity<T> *>();
  _gui = new GDLGUI<T>(*_drawQueue, _entityMap, _characterMap, _settings);
  _AICondVar = new CondVar(_AIMutex);
  _soundManager = new SoundManager();
  _eventManager = new EventManager<T>(*_gui, *_drawQueue, _entityMap, _characterMap, _factory, *_AICondVar, *_soundManager, _settings);
  _menuManager = new MenuManager<T>(*_gui, _settings, *_soundManager);
}

template <typename T>
Core<T>::~Core(void)
{
      delete _eventManager;
      delete _gui;
      delete _drawQueue;
      _AICondVar->broadcast();
      delete _AICondVar;
      delete _soundManager;
      delete _menuManager;
}

template <typename T>
void		Core<T>::loadGame()
{
  _soundManager->initSound();
  _soundManager->playSound(S_INTRO);
  _menuManager->callMenu(INTRO);
}

template <typename T>
eMenuEvent		Core<T>::loadMenu()
{
  _soundManager->playSound(S_MENU, true);
  return (_menuManager->callMenu(START));
}

template <typename T>
void		Core<T>::gameLoop(void)
{
  loadGame();
  if (loadMenu() != EXIT)
    {
      _lua.mapGenerate(_settings.getMapSize(), _settings.getMapSize());
      _lua.playerMapGenerate(_settings.getPlayerNumber() + _settings.getAINumber());
      _entityMap = _lua.getMap();
      _characterMap = _lua.getPMap();
      _eventManager->init();
      _gui->init();
      _soundManager->playSound(S_GAME, true);
      while(!(_eventManager->isEnd()))
	{
	  if (_eventManager->update() && !(_eventManager->isEnd()))
	    {
	      _gui->draw();
	      _AICondVar->broadcast();
	    }
	}
      if (_eventManager->isWin())
	_menuManager->callMenu(WIN);
      else
	_menuManager->callMenu(LOSE);
    }
}

template <typename T>
MenuManager<T>	Core<T>::getMenuManager(void) const
{
  return (*_menuManager);
}
