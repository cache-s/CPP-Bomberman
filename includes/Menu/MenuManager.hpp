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

enum				eMenu
  {
    INTRO = 1,
    START = 2,
    SETTINGS = 3,
    LOAD = 4,
    PAUSE = 5,
    END = 6,
  };

template <class T>
class				MenuManager
{
public:
  MenuManager(IGUI<T>& gui, Settings& settings);
  ~MenuManager();

  void				callMenu(eMenu menu);

private:
  int				callIntro();
  int				callStart();
  int				callLoad();
  int				callSettings();
  int				callPause();
  int				callEnd();

  typedef int (MenuManager<T>::*callMenuFct)();
  std::map<eMenu, callMenuFct> _callMenuFct;

  IGUI<T>			&_gui;
  Settings			&_settings;
  eKey				_lastKeyPressed;

  MenuStart			_menuStart;
  MenuSettings			_menuSettings;
  MenuLoad			_menuLoad;
  MenuPause			_menuPause;
  MenuEnd			_menuEnd;
};

# include			"MenuManager.tpp"

#endif				//MENUMANAGER_HPP_
