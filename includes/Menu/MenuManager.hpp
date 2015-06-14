#ifndef				MENUMANAGER_HPP_
# define			MENUMANAGER_HPP_

# include			"MenuStart.hpp"
# include			"MenuLoad.hpp"
# include			"MenuSettings.hpp"
# include			"MenuPause.hpp"
# include			"MenuEnd.hpp"

# include			"IGUI.hpp"
# include			"Settings.hpp"
# include			"EventManager.hpp"
# include			"SoundManager.hpp"

enum				eMenuEvent
  {
    LAUNCH = 1,
    RESUME = 2,
    SAVE = 3,
    LOADGAME = 4,
    MAIN = 5,
    EXIT = 6,
    NOTHING = 7
  };

enum				eMenu
  {
    INTRO = 1,
    START = 2,
    SETTINGS = 3,
    LOAD = 4,
    PAUSE = 5,
    WIN = 7,
    LOSE = 6
  };

template <class T>
class				MenuManager
{
public:
  MenuManager(IGUI<T>& gui, Settings& settings, SoundManager& sM);
  ~MenuManager();

  eMenuEvent			callMenu(eMenu menu);

private:

  std::string			getString(int result);
  int				getNumber(int min, int max, int current);

  eMenuEvent			callIntro();
  eMenuEvent			callStart();
  eMenuEvent			callLoad();
  eMenuEvent			callSettings();
  eMenuEvent			callPause();
  eMenuEvent			callWin();
  eMenuEvent			callLose();
  eMenuEvent			callEnd(int index);

  typedef eMenuEvent (MenuManager<T>::*callMenuFct)();
  std::map<eMenu, callMenuFct> _callMenuFct;
  IGUI<T>			&_gui;
  Settings			&_settings;
  SoundManager			&_sM;
  eKey				_lastKeyPressed;

  MenuStart			_menuStart;
  MenuSettings			_menuSettings;
  MenuLoad			_menuLoad;
  MenuPause			_menuPause;
  MenuEnd			_menuEnd;
};

# include			"MenuManager.tpp"

#endif				//MENUMANAGER_HPP_
