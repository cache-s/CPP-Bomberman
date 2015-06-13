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
std::string			MenuManager<T>::getString(int result)
{
  std::string			str;
  unsigned int			uvalue = result;
  int				digits = 3;

  while (digits-- > 0)
    {
      str += ('0' + uvalue % 10);
      uvalue /= 10;
    }

  std::reverse(str.begin(), str.end());
  return str;
}


template <class T>
int				MenuManager<T>::getNumber(int min, int max, int current)
{
  int				result = current;

  _gui.drawMenu(_menuSettings.getIndex());
  _gui.drawNumber(getString(result));
  while ((_lastKeyPressed = _gui.menuPollEvent()) != BOMB1)
    {
      if (_lastKeyPressed == LEFT1 && result > min)
        result--;
      if (_lastKeyPressed == RIGHT1 && result < max)
        result++;
      _gui.drawMenu(_menuSettings.getIndex());
      _gui.drawNumber(getString(result));
    }
  return (result);
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
          if (_menuSettings.getIndex() == 4)
            return (callStart());
          else
            if (_menuSettings.getIndex() == 0)
              _settings.setMapSize(getNumber(5, 999, _settings.getMapSize()));
	  if (_menuSettings.getIndex() == 1)
	    _settings.setPlayerNumber(getNumber(1, 2, _settings.getPlayerNumber()));
	  if (_menuSettings.getIndex() == 2)
	    _settings.setAINumber(getNumber(0, 1, _settings.getAINumber()));
	  if (_menuSettings.getIndex() == 3)
	    _settings.setSoundVolume(getNumber(0, 10, _settings.getSoundVolume()));
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
  int				pos = 0;
  std::string			name = "aaa";

  _gui.menuLoadTexture(_menuEnd.getScene());
  _gui.drawMenu(_menuEnd.getIndex());
  while ((_lastKeyPressed = _gui.menuPollEvent()) != BOMB1)
    {
      if (_lastKeyPressed == LEFT1 && pos != 0)
	pos--;
      if (_lastKeyPressed == RIGHT1 && pos != 2)
	pos++;
      if (_lastKeyPressed == UP1 && name[pos] != 'z')
	name[pos] = name[pos] + 1;
      if (_lastKeyPressed == DOWN1 && name[pos] != 'a')
	name[pos] = name[pos] - 1;

      _gui.drawMenu(_menuEnd.getIndex());
      usleep(100000);
    }
  return (EXIT);
}
