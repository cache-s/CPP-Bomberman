//
// AEntity.hpp for  in /home/poupon_d/rendu/cpp_bomberman/sources/Entity
// 
// Made by delphine poupon
// Login   <poupon_d@epitech.net>
// 
// Started on  Tue May 19 14:22:52 2015 delphine poupon
// Last update Tue May 19 14:22:52 2015 delphine poupon
//

#ifndef				AENTITY_HHP_
# define			AENTITY_HHP_

#include			"IEntity.hpp"

template<typename T>
template<typename U>
class				AEntity : public IEntity
{
public:  
  virtual int			getPosX() const;
  virtual int			getPosY() const;

private:
  int				_x;
  int				_y;
  int				_hitboxSize;
  bool				_isBreakable;
  gdl:texture			_texture;
  T				_model;
  U(glm::vec3)			_position;
  U(glm::vec3)			_rotation;
  U(glm::vec3)			_scale;
};

#endif				/* AENTITY_HPP_ */
