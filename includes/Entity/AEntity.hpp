#ifndef				AENTITY_HPP_
# define			AENTITY_HPP_

# include			<Texture.hh>
# include			"IEntity.hpp"

template<class T, class U, class V>
class				AEntity : public IEntity
{
public:
  virtual int			getPosX() const { return (_x); } 
  virtual int			getPosY() const { return (_y); }
  virtual eEntityType		getType() const = 0;
private:
  int				_x;
  int				_y;
  int				_hitboxSize;
  bool				_isBreakable;
  V				_texture;
  T				_model;
  U				_position;
  U				_rotation;
  U				_scale;
};

#endif				/* AENTITY_HPP_ */
