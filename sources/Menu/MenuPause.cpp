#include			"MenuPause.hpp"

MenuPause::MenuPause()
{
  _index = 0;

  _scene.push_back("./assets/menu/Pause_Resume.tga");
  _scene.push_back("./assets/menu/Pause_Save.tga");
  _scene.push_back("./assets/menu/Pause_Settings.tga");
  _scene.push_back("./assets/menu/Pause_Menu.tga");
  _scene.push_back("./assets/menu/Pause_Exit.tga");
}

MenuPause::~MenuPause()
{

}

void				MenuPause::setIndex(int index)
{
  _index = index;
}

int				MenuPause::getIndex(void) const
{
  return (_index);
}

int				MenuPause::getMaxIndex(void) const
{
  return (_scene.size() - 1);
}

std::string			MenuPause::getCurrentScene(void) const
{
  return (_scene[_index]);
}

std::vector<std::string>	MenuPause::getScene() const
{
  return (_scene);
}
