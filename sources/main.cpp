#include		"Bomberman.hpp"
#include		"Factory.hpp"
#include		"Core.hpp"
#include		"SoundManager.hpp"

int			main()
{
  Core<glm::vec3>	core;

  core.getMenuManager().callMenu(START);
  core.gameLoop();
  return (0);
}
