#include		"Bomberman.hpp"
#include		"Factory.hpp"
#include		"Core.hpp"
#include		"SoundManager.hpp"

int			main()
{
  SoundManager		s;
  s.playSound(S_INTRO);
  s.playSound(S_TICK);
  s.playSound(S_EXPLOSION);
  s.playSound(S_BONUS);
  s.playSound(S_BOMB);
  s.playSound(S_VICTORY);
  s.playSound(S_DEATH);
  s.playSound(S_MENU, true);
  Core<glm::vec3>	core;

  core.gameLoop();
  return (0);
}
