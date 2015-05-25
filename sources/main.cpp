#include		"bomberman.hpp"
#include		"GDLGUI.hpp"

int			main(int ac, char** av)
{
  (void)ac, (void)av;
  IGUI			*tmp = new GDLGUI;

  tmp->windowInit();
  tmp->cameraInit();
  tmp->shaderInit();
  tmp->soundInit();
  // while (tmp.update() == true)
  //   tmp.draw();
  return (0);
}
