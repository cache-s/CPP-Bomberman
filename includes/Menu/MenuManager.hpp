#ifndef				MENUMANAGER_HPP_
# define			MENUMANAGER_HPP_

# include			"MenuStart.hpp"
# include			"MenuPause.hpp"
# include			"MenuEnd.hpp"

# include			"GDLGUI.hpp"
# include			"Settings.hpp"

class				MenuManager
{
public:
  MenuManager(GDLGUI<glm::vec3>* gui, Settings* settings);
  ~MenuManager();

private:
  Settings*			_settings;
  GDLGUI<glm::vec3>*		_gui;
  MenuStart			_menuStart;
  MenuPause			_menuPause;
  MenuEnd			_menuEnd;
};

#endif				//MENUMANAGER_HPP_
