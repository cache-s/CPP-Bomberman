#include		"Bomberman.hpp"
#include		"GDLGUI.hpp"
#include		"Factory.hpp"
#include		"MapGen.hpp"

int			main(int ac, char** av)
{
  std::map<std::pair<int, int>, IEntity<glm::vec3> *> mapped;
  MapGen					mapGen;

  (void)ac, (void)av;
  GDLGUI<glm::vec3>			*tmp = new GDLGUI<glm::vec3>;
  std::vector<IEntity<glm::vec3> *>	_ents;
  Factory<glm::vec3>			factory;

  std::map<std::pair<int, int>, IEntity<glm::vec3> *> entMap =  mapGen.mapGenerate(10, 10);
  _ents.push_back(factory.createEntity(BOMB, 10, 10));
  _ents.push_back(factory.createEntity(PLAYER, 0, 0));
  _ents.push_back(factory.createEntity(FLOOR, 5, 5));
  _ents.push_back(factory.createEntity(UBRKWALL, 3, 3));
  _ents.push_back(factory.createEntity(BRKWALL, 0, 0));
  _ents.push_back(factory.createEntity(ARTINT, 10, 10));
  tmp->windowInit();
  tmp->cameraInit();
  tmp->shaderInit();
  tmp->assetsInit();
  while (tmp->update(_ents) == true)
    {
      tmp->setEntitiesToDraw(_ents);
      tmp->drawMap(entMap);
      tmp->draw();
    }
  return (0);
}
