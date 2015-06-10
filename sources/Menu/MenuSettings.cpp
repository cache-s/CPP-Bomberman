#include			"MenuSettings.hpp"

MenuSettings::MenuSettings()
{
  _index = 0;

  _scene.push_back("./assets/menu/Settings_Play.tga");
  _scene.push_back("./assets/menu/Settings_Back.tga");
}

MenuSettings::~MenuSettings()
{

}

void				MenuSettings::setIndex(int index)
{
  _index = index;
}

int				MenuSettings::getIndex(void) const
{
  return (_index);
}

int				MenuSettings::getMaxIndex(void) const
{
  return (_scene.size() - 1);
}

std::string			MenuSettings::getCurrentScene(void) const
{
  return (_scene[_index]);
}

std::vector<std::string>	MenuSettings::getScene() const
{
  return (_scene);
}
