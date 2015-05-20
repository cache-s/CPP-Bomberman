#ifndef		GDLGUI_HPP_
# define	GDLGUI_HPP_

# include	<iostream>
# include	<Game.hh>
# include       <glm/glm.hpp>
# include       <glm/gtc/matrix_transform.hpp>
# include	<BasicShader.hh>
# include	<SdlContext.hh>
# include	"IGUI.hpp"

class GDLGUI : public IGUI
{
public:
  GDLGUI();

  void windowInit();
  void cameraInit();
  void shaderInit();
  void soundInit();
  bool update();
  void draw();
  void pollEvent();
  void pause();
private:
  gdl::SdlContext	_context;
  glm::mat4		_camProj;
  glm::mat4		_camTransf;
  gdl::BasicShader	_shader;
  gdl::Input		_input;
  gdl::Clock		_clock;
};

#endif		/* GDLGUI_HPP_*/
