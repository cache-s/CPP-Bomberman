//
// GameEngine.hh for bomber in /home/chazot_a/rendu/cpp_bomberman/tp
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Fri May  8 14:16:37 2015 Jordan Chazottes
// Last update Thu May 28 15:45:41 2015 Jordan Chazottes
//

#ifndef		GAMEENGINE_HH_
# define	GAMEENGINE_HH_

# pragma	once
# include	<Game.hh>
# include	<SdlContext.hh>
# include	<BasicShader.hh>

# include	<iostream>
# include	<vector>

# include	"AObject.hh"
# include	"Map.hh"
# include	"Cube.hh"
# include	"Character.hh"

class GameEngine : public gdl::Game
{
private:
  gdl::SdlContext	_context;
  gdl::Clock		_clock;
  gdl::Input		_input;
  gdl::BasicShader	_shader;
  std::vector<AObject*>	_objects;
  AObject*		_character;
  glm::mat4		_transformation;
  glm::vec3	setCamPos();
public:
  GameEngine();
  ~GameEngine();
  bool	initialize();
  bool	update();
  void	draw();
};

#endif // GAMEENGINE_HH_
