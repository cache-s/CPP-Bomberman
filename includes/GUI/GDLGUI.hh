//
// GDLGUI.hh for bomber in /home/chazot_a/rendu/cpp_bomberman/sources/GUI
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Tue May 19 11:47:41 2015 Jordan Chazottes
// Last update Tue May 19 15:44:47 2015 Jordan Chazottes
//

#ifndef		GDLGUI_HH_
# define	GDLGUI_HH_

# include	<iostream>
# include	"IGUI.hh"

class GDLGUI : public IGUI
{
public:
  GDLGUI();
  void windowInit();
  void soundInit();
  void update();
  void draw();
  void pollEvent();
  void pause();
private:
};

#endif		/* GDLGUI_HH_*/
