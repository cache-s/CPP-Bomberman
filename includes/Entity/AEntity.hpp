#ifndef				AENTITY_HPP_
# define			AENTITY_HPP_

# include			<Texture.hh>
# include			"IEntity.hpp"

template<class T>
class				AEntity : public IEntity<T>
{
public:
  virtual int			getPosX() const { return (_x); } 
  virtual int			getPosY() const { return (_y); }
  virtual void			setPosX(int x) { _x = x; }
  virtual void			setPosY(int y) { _y = y; }
  virtual IEntity<T>		*clone() { return (new IEntity<T>(*this)); }
  virtual eEntityType		getType() const = 0;
private:
  int				_x;
  int				_y;
  int				_hitboxSize;
  bool				_isBreakable;
  // V				_texture;
  // T				_model;
  T				_position;
  T				_rotation;
  T				_scale;
};

#endif				/* AENTITY_HPP_ */
