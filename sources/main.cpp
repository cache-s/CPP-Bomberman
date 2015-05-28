#include		"Bomberman.hpp"
#include		"GDLGUI.hpp"
#include		"Factory.hpp"

int			main(int ac, char** av)
{
  (void)ac, (void)av;
  IGUI			*tmp = new GDLGUI;
  std::vector<IEntity<glm::vec3> *> _ents;
  Factory<glm::vec3> 	factory;

  _ents.push_back(factory.createEntity(BOMB, 10, 10));
  _ents.push_back(factory.createEntity(PLAYER, 10, 10));
  _ents.push_back(factory.createEntity(ARTINT, 10, 10));
  tmp->windowInit();
  tmp->cameraInit();
  tmp->shaderInit();
  tmp->soundInit();
  while (tmp->update() == true)
    tmp->draw(_ents);
  return (0);
}
