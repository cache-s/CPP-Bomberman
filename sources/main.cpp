#include		"Bomberman.hpp"
#include		"Factory.hpp"
#include		"Core.hpp"

int			main()
{
  Core<glm::vec3>	core;

  core.gameLoop();
  return (0);
}
