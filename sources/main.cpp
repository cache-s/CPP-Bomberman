#include		"Bomberman.hpp"
#include		"GDLGUI.hpp"
#include		"Factory.hpp"
#include		"Lua.hpp"

int			main(int ac, char** av)
{
  std::map<std::pair<int, int>, IEntity<glm::vec3> *> mapped;
  Lua					lua;

  (void)ac, (void)av;
  GDLGUI<glm::vec3>			*tmp = new GDLGUI<glm::vec3>;
  // std::vector<IEntity<glm::vec3> *>	_ents;
  // Factory<glm::vec3>			factory;


  // mapped = lua.mapGenerate(3,3);
  // _ents.push_back(factory.createEntity(BOMB, 10, 10));
  // _ents.push_back(factory.createEntity(PLAYER, 0, 0));
  // std::cout << _ents[0]->getType() << std::endl;
  // _ents.push_back(factory.createEntity(ARTINT, 10, 10));
  // tmp->windowInit();
  // tmp->cameraInit();
  // tmp->shaderInit();
  // tmp->assetsInit();
  tmp->drawMap(lua.mapGenerate(100, 100));
  // while (tmp->update(_ents) == true)
  //   {
  //     tmp->setEntitiesToDraw(_ents);
  //     tmp->draw();
  //   }
  // return (0);
}
