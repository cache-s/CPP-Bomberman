#include			"MenuStart.hpp"

MenuStart::MenuStart()
{
  _index = 0;

  _scene.push_back("./assets/menu/Start_Play.tga");
  _scene.push_back("./assets/menu/Start_Load.tga");
  _scene.push_back("./assets/menu/Start_Score.tga");
  _scene.push_back("./assets/menu/Start_Settings.tga");
  _scene.push_back("./assets/menu/Start_Exit.tga");
}

MenuStart::~MenuStart()
{

}

void				MenuStart::setIndex(int index)
{
  _index = index;
}

int				MenuStart::getIndex(void) const
{
  return (_index);
}

int				MenuStart::getMaxIndex(void) const
{
  return (_scene.size() - 1);
}

std::vector<std::string>		MenuStart::getScene() const
{
  return (_scene);
}
