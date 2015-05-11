//
// Cube.hh for cpp_bomber in /home/chazot_a/rendu/cpp_bomberman/tp
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Fri May  8 14:47:19 2015 Jordan Chazottes
// Last update Sun May 10 15:00:47 2015 Jordan Chazottes
//

#ifndef		CUBE_HH_
# define	CUBE_HH_

# include	<Texture.hh>
# include	<Geometry.hh>

# include	"AObject.hh"

class Cube : public AObject
{
private:
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;
  float		_speed;
public:
		Cube();
  Cube(glm::vec3, glm::vec3, glm::vec3);
  virtual	~Cube();
  virtual bool	initialize();
  virtual void	update(gdl::Clock const& clock, gdl::Input& input);
  virtual void	draw(gdl::AShader &shader, gdl::Clock const& clock);
};

#endif //Cube_HH_
