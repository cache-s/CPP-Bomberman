#include			"MenuLoad.hpp"

MenuLoad::MenuLoad()
{
  _index = 0;

  _scene.push_back("./assets/menu/Load_Slot1.tga");
  _scene.push_back("./assets/menu/Load_Slot2.tga");
  _scene.push_back("./assets/menu/Load_Slot3.tga");
  _scene.push_back("./assets/menu/Load_Back.tga");
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
