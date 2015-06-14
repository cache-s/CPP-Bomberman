#include			"MenuScore.hpp"

MenuScore::MenuScore()
{
  _index = 0;

  _scene.push_back("./assets/menu/Score_Back.tga");
}

MenuScore::~MenuScore()
{

}

void				MenuScore::setIndex(int index)
{
  _index = index;
}

int				MenuScore::getIndex(void) const
{
  return (_index);
}

int				MenuScore::getMaxIndex(void) const
{
  return (_scene.size() - 1);
}

std::vector<std::string>	MenuScore::getScene() const
{
  return (_scene);
}
