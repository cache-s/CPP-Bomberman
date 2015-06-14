#include			"MenuEnd.hpp"

MenuEnd::MenuEnd()
{
  _index = 0;

  _scene.push_back("./assets/menu/Win.tga");
  _scene.push_back("./assets/menu/Lose.tga");
}

MenuEnd::~MenuEnd()
{

}

void				MenuEnd::setIndex(int index)
{
  _index = index;
}

int				MenuEnd::getIndex(void) const
{
  return (_index);
}

int				MenuEnd::getMaxIndex(void) const
{
  return (_scene.size() - 1);
}

std::vector<std::string>	MenuEnd::getScene() const
{
  return (_scene);
}
