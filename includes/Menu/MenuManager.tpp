#include			"MenuManager.hpp"

template <class T>
MenuManager<T>::MenuManager(IGUI<T> &gui, Settings &settings, SoundManager &sM) : _gui(gui), _settings(settings), _sM(sM)
{
  _callMenuFct[INTRO] = &MenuManager<T>::callIntro;
  _callMenuFct[START] = &MenuManager<T>::callStart;
  _callMenuFct[SETTINGS] = &MenuManager<T>::callSettings;
  _callMenuFct[LOAD] = &MenuManager<T>::callLoad;
  _callMenuFct[PAUSE] = &MenuManager<T>::callPause;
  _callMenuFct[END] = &MenuManager<T>::callEnd;
}

template <class T>
MenuManager<T>::~MenuManager()
{

}

template <class T>
eMenuEvent			MenuManager<T>::callMenu(eMenu menu)
{
  _gui.menuInit();

  return ((this->*_callMenuFct[menu])());
}

template <class T>
eMenuEvent			MenuManager<T>::callIntro()
{
  std::vector<std::string>	intro;

  intro.push_back("./assets/menu/Intro.tga");
  _gui.menuLoadTexture(intro);
  _gui.drawMenu(0);
  usleep(7000000);
  return (NOTHING);
}

template <class T>
eMenuEvent			MenuManager<T>::callStart()
{
  _gui.menuLoadTexture(_menuStart.getScene());
  _gui.drawMenu(_menuStart.getIndex());
  while ((_lastKeyPressed = _gui.menuPollEvent()) != QUIT)
    {
      _sM.playSound(S_TICK);
      if (_lastKeyPressed == BOMB1)
	{
	  if (_menuStart.getIndex() == 0)
	    return (LAUNCH);
	  if (_menuStart.getIndex() == 1)
	    return (callLoad());
	  if (_menuStart.getIndex() == 2)
	    return (callSettings());
	  if (_menuStart.getIndex() == 3)
	    return (EXIT);
	}
      if (_menuStart.getIndex() == 0 && _lastKeyPressed == UP1)
	_menuStart.setIndex(_menuStart.getMaxIndex());
      else if (_menuStart.getIndex() == _menuStart.getMaxIndex() && _lastKeyPressed == DOWN1)
	_menuStart.setIndex(0);
      else
	{
	  if (_lastKeyPressed == UP1)
	    _menuStart.setIndex(_menuStart.getIndex() - 1);
	  if (_lastKeyPressed == DOWN1)
	    _menuStart.setIndex(_menuStart.getIndex() + 1);
	}
      _gui.drawMenu(_menuStart.getIndex());
      usleep(100000);
    }
  return (EXIT);
}

template <class T>
eMenuEvent			MenuManager<T>::callSettings()
{
  _gui.menuLoadTexture(_menuSettings.getScene());
  _gui.drawMenu(_menuSettings.getIndex());
  while ((_lastKeyPressed = _gui.menuPollEvent()) != QUIT)
    {
      _sM.playSound(S_TICK);
      if (_lastKeyPressed == BOMB1)
	{
	  if (_menuSettings.getIndex() == 0)
	    return (LAUNCH);
	  if (_menuSettings.getIndex() == 1)
	    return (callStart());
	}
      if (_menuSettings.getIndex() == 0 && _lastKeyPressed == UP1)
	_menuSettings.setIndex(_menuSettings.getMaxIndex());
      else if (_menuSettings.getIndex() == _menuSettings.getMaxIndex() && _lastKeyPressed == DOWN1)
	_menuSettings.setIndex(0);
      else
	{
	  if (_lastKeyPressed == UP1)
	    _menuSettings.setIndex(_menuSettings.getIndex() - 1);
	  if (_lastKeyPressed == DOWN1)
	    _menuSettings.setIndex(_menuSettings.getIndex() + 1);
	}
      _gui.drawMenu(_menuSettings.getIndex());
      usleep(100000);
    }
  return (EXIT);
}

template <class T>
eMenuEvent			MenuManager<T>::callLoad()
{
  _gui.menuLoadTexture(_menuLoad.getScene());
  _gui.drawMenu(_menuLoad.getIndex());
  while ((_lastKeyPressed = _gui.menuPollEvent()) != QUIT)
    {
      _sM.playSound(S_TICK);
      if (_lastKeyPressed == BOMB1)
	{
	  if (_menuSettings.getIndex() == 0)
	    return (callStart());
	}
      if (_menuLoad.getIndex() == 0 && _lastKeyPressed == UP1)
	_menuLoad.setIndex(_menuLoad.getMaxIndex());
      else if (_menuLoad.getIndex() == _menuLoad.getMaxIndex() && _lastKeyPressed == DOWN1)
	_menuLoad.setIndex(0);
      else
	{
	  if (_lastKeyPressed == UP1)
	    _menuLoad.setIndex(_menuLoad.getIndex() - 1);
	  if (_lastKeyPressed == DOWN1)
	    _menuLoad.setIndex(_menuLoad.getIndex() + 1);
	}
      _gui.drawMenu(_menuLoad.getIndex());
      usleep(100000);
    }
  return (EXIT);
}

template <class T>
eMenuEvent			MenuManager<T>::callPause()
{
  _gui.menuLoadTexture(_menuPause.getScene());
  _gui.drawMenu(_menuPause.getIndex());
  while ((_lastKeyPressed = _gui.menuPollEvent()) != QUIT)
    {
      _sM.playSound(S_TICK);
      if (_lastKeyPressed == BOMB1)
	{
	  if (_menuStart.getIndex() == 0)
	    return (RESUME);
	  if (_menuStart.getIndex() == 1)
	    return (SAVE);
	  if (_menuStart.getIndex() == 2)
	    return (callSettings());
	  if (_menuStart.getIndex() == 3)
	    return (MAIN);
	  if (_menuStart.getIndex() == 4)
	    return (EXIT);
	}
      if (_menuPause.getIndex() == 0 && _lastKeyPressed == UP1)
	_menuPause.setIndex(_menuPause.getMaxIndex());
      else if (_menuPause.getIndex() == _menuPause.getMaxIndex() && _lastKeyPressed == DOWN1)
	_menuPause.setIndex(0);
      else
	{
	  if (_lastKeyPressed == UP1)
	    _menuPause.setIndex(_menuPause.getIndex() - 1);
	  if (_lastKeyPressed == DOWN1)
	    _menuPause.setIndex(_menuPause.getIndex() + 1);
	}
      _gui.drawMenu(_menuPause.getIndex());
      usleep(100000);
    }
  return (EXIT);
}

template <class T>
eMenuEvent			MenuManager<T>::callEnd()
{
  _gui.menuLoadTexture(_menuEnd.getScene());
  _gui.drawMenu(_menuEnd.getIndex());
  while ((_lastKeyPressed = _gui.menuPollEvent()) != QUIT)
    {
      if (_menuEnd.getIndex() == 0 && _lastKeyPressed == UP1)
	_menuEnd.setIndex(_menuEnd.getMaxIndex());
      else if (_menuEnd.getIndex() == _menuEnd.getMaxIndex() && _lastKeyPressed == DOWN1)
	_menuEnd.setIndex(0);
      else
	{
	  if (_lastKeyPressed == UP1)
	    _menuEnd.setIndex(_menuEnd.getIndex() - 1);
	  if (_lastKeyPressed == DOWN1)
	    _menuEnd.setIndex(_menuEnd.getIndex() + 1);
	}
      _gui.drawMenu(_menuEnd.getIndex());
      usleep(100000);
    }
  return (EXIT);
}
