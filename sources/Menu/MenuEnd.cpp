#include			"MenuEnd.hpp"

MenuEnd::MenuEnd()
{
  _index = 0;
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

std::string			MenuEnd::getCurrentScene(void) const
{
  return (_scene[_index]);
}

std::vector<std::string>	MenuEnd::getScene() const
{
  return (_scene);
}
