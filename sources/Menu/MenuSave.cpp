#include			"MenuSave.hpp"

MenuSave::MenuSave()
{
  _index = 0;

  _scene.push_back("./assets/menu/Save_Slot1.tga");
  _scene.push_back("./assets/menu/Save_Slot2.tga");
  _scene.push_back("./assets/menu/Save_Slot3.tga");
  _scene.push_back("./assets/menu/Save_Back.tga");
}

MenuSave::~MenuSave()
{

}

void				MenuSave::setIndex(int index)
{
  _index = index;
}

int				MenuSave::getIndex(void) const
{
  return (_index);
}

int				MenuSave::getMaxIndex(void) const
{
  return (_scene.size() - 1);
}

std::vector<std::string>	MenuSave::getScene() const
{
  return (_scene);
}
