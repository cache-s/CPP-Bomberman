#include <cstdlib>
#include "GameEngine.hpp"
#include <unistd.h>
#include <iostream>
int main()
{
  // On cree son engine
  GameEngine engine;
  if (engine.initialize() == false)
    {
      std::cout << "TAMERE" << std::endl;
      return (EXIT_FAILURE);
    }
  while (engine.update() == true)
    engine.draw();
  std::cout << "TAMERE" << std::endl;
  return EXIT_SUCCESS;
}
