//
// Character.hh for cpp_bomber in /home/chazot_a/rendu/cpp_bomberman/tp
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Fri May  8 17:11:48 2015 Jordan Chazottes
// Last update Mon May 11 09:55:34 2015 Jordan Chazottes
//

#ifndef		CHARACTER_HH_
# define	CHARACTER_HH_

# include	<Texture.hh>
# include	<Geometry.hh>
# include	<Model.hh>

# include	"AObject.hh"

class Character : public AObject
{
private:
  glm::vec3	getPosition() const;
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;
  gdl::Model	_model;
  float		_speed;
public:
		Character();
  Character(glm::vec3, glm::vec3, glm::vec3);
  virtual	~Character();
  virtual bool	initialize();
  virtual void	update(gdl::Clock const& clock, gdl::Input& input);
  virtual void	draw(gdl::AShader& shader, gdl::Clock const &clock);
};

#endif		// CHARACTER_HH_
