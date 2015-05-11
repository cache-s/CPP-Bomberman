//
// AObject.hh for cpp_bomber in /home/chazot_a/rendu/cpp_bomberman/tp
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Fri May  8 18:26:17 2015 Jordan Chazottes
// Last update Mon May 11 09:54:03 2015 Jordan Chazottes
//

#ifndef		AOBJECT_HH_
# define	AOBJECT_HH_

# include	<SdlContext.hh>
# include	<BasicShader.hh>
# include	<glm/glm.hpp>
# include	<glm/gtc/matrix_transform.hpp>
# include	<iostream>

class	AObject
{
protected:
  glm::vec3	_position;
  glm::vec3	_rotation;
  glm::vec3	_scale;
public:
  AObject();
  AObject(glm::vec3, glm::vec3, glm::vec3);
  virtual ~AObject();
  virtual bool	initialize();
  virtual void	update(gdl::Clock const &clock, gdl::Input &input);
  virtual void	draw(gdl::AShader &shader, gdl::Clock const &clock) = 0;
  void		translate(glm::vec3 const &v);
  void		rotate(glm::vec3 const& axis, float angle);
  void		scale(glm::vec3 const& scale);
  glm::mat4	getTransformation();
  glm::vec3	getPosition() const;
};

#endif
