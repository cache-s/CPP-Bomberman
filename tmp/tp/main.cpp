#include <cstdlib>
#include "GameEngine.hh"
#include <unistd.h>
#include <iostream>

int main()
{
  // On cree son engine
  GameEngine engine;
  if (engine.initialize() == false)
    {
      std::cout << "error init" << std::endl;
      return (EXIT_FAILURE);
    }
  while (engine.update() == true)
    engine.draw();
  return EXIT_SUCCESS;
}
