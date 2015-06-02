//
// Core.cpp for Bomberman in /home/porres_m/Projets/Cpp/Bomberman/cpp_bomberman/sources/Core
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Sun May 24 18:01:57 2015 Martin Porrès
// Last update Tue Jun  2 18:14:45 2015 Martin Porrès
//

#include	"Core.hpp"

Core::Core(IGUI &gui) : _gui(&gui)
{
  //generate map / load map
}

Core::~Core(void)
{

}

void		Core::gameLoop(void)
{
  while(true) // while game is running
    {
      if (_eventManager.update())
	{
	  signalDraw();
	  _gui.draw();
	}
    }
}

void		Core::signalDraw(void)
{
  _drawCondVar.signal();
}
