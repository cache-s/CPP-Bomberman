//
// AObject.cpp for cpp_bomber in /home/chazot_a/rendu/cpp_bomberman/tp
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Fri May  8 18:30:04 2015 Jordan Chazottes
// Last update Tue Jun  2 16:46:17 2015 Jordan Chazottes
//

# include	"AObject.hh"

AObject::AObject() : _position(0, 0, 0), _rotation(0, 0, 0), _scale(1, 1, 1)
{
}

AObject::AObject(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) : _position(position), _rotation(rotation), _scale(scale)
{
}


AObject::~AObject()
{
}

bool	AObject::initialize()
{
  return (true);
}

void	AObject::update(gdl::Clock const &clock, gdl::Input &input)
{
}

void	AObject::translate(glm::vec3 const &v)
{
  _position += v;
}

void	AObject::rotate(glm::vec3 const& axis, float angle)
{
  _rotation += axis * angle;
}

void	AObject::scale(glm::vec3 const& scale)
{
  _scale *= scale;
}

glm::mat4 AObject::getTransformation()
{
  glm::mat4 transform(1);
  transform = glm::rotate(transform, _rotation.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, _rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, _rotation.z, glm::vec3(0, 0, 1));
  transform = glm::translate(transform, _position);
  transform = glm::scale(transform, _scale);
  return (transform);
}

glm::vec3	AObject::getPosition() const
{
  return _position;
}
