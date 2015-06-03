#include		"Bomberman.hpp"
#include		"GDLGUI.hpp"
#include		"Factory.hpp"
#include		"Lua.hpp"

int main()
{
  Lua	llua;

<<<<<<< HEAD
  // _ents.push_back(factory.createEntity(BOMB, 10, 10));
  _ents.push_back(factory.createEntity(PLAYER, 0, 0));
  // _ents.push_back(factory.createEntity(ARTINT, 10, 10));
  tmp->windowInit();
  tmp->cameraInit();
  tmp->shaderInit();
  tmp->assetsInit();
  while (tmp->update(_ents) == true)
    {
      // tmp->drawMenu("../assets/menu/StartMenuDefault.tga");
      tmp->setEntitiesToDraw(_ents);
      tmp->draw();
    }
  return (0);
=======
  llua.mapGenerate(10, 10);
>>>>>>> c688b1ef9235ea115c01043547421c4443ea1e20
}

// int			main(int ac, char** av)
// {
//   (void)ac, (void)av;
//   GDLGUI<glm::vec3>			*tmp = new GDLGUI<glm::vec3>;
//   std::vector<IEntity<glm::vec3> *> _ents;
//   Factory<glm::vec3> 	factory;

//   // _ents.push_back(factory.createEntity(BOMB, 10, 10));
//   _ents.push_back(factory.createEntity(PLAYER, 0, 0));
//   // _ents.push_back(factory.createEntity(ARTINT, 10, 10));
//   tmp->windowInit();
//   tmp->cameraInit();
//   tmp->shaderInit();
//   tmp->assetsInit();
//   tmp->drawMenu("/home/charie_p/rendu/cpp_bomberman/assets/menu/StartMenuPlaySelected.tga");
//   while(42);
//   // while (tmp->update(_ents) == true)
//   //   {
//       // tmp->setEntitiesToDraw(_ents);
//       // tmp->draw();
//     // }
//   return (0);
// }
