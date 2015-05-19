//
// IGUI.hh for bomber in /home/chazot_a/rendu/cpp_bomberman/sources/GUI
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Tue May 19 11:38:03 2015 Jordan Chazottes
// Last update Tue May 19 11:41:41 2015 Jordan Chazottes
//

#ifndef		IGUI_HH_
# define	IGUI_HH_

class IGUI
{
public:
  virtual void windowInit() = 0;
  virtual void soundInit() = 0;
  virtual void update() = 0;
  virtual void draw() = 0;
  virtual void pollEvent() = 0;
  virtual void pause() = 0;
private:
};

#endif		/* IGUI_HH_ */
