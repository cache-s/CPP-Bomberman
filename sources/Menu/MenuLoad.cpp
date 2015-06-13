#include			"MenuLoad.hpp"

MenuLoad::MenuLoad()
{
  _index = 0;

  _scene.push_back("./assets/menu/Start_Play.tga");
  _scene.push_back("./assets/menu/Start_Load.tga");
  _scene.push_back("./assets/menu/Start_Settings.tga");
  _scene.push_back("./assets/menu/Start_Exit.tga");
}

MenuLoad::~MenuLoad()
{

}

void				MenuLoad::setIndex(int index)
{
  _index = index;
}

int				MenuLoad::getIndex(void) const
{
  return (_index);
}

int				MenuLoad::getMaxIndex(void) const
{
  return (_scene.size() - 1);
}

std::vector<std::string>	MenuLoad::getScene() const
{
  return (_scene);
}
