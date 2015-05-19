#ifndef		GDLGUI_HPP_
# define	GDLGUI_HPP_

# include	<iostream>
# include	"IGUI.hpp"

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

#endif		/* GDLGUI_HPP_*/
