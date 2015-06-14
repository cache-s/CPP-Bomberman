#ifndef				AENTITY_HPP_
# define			AENTITY_HPP_

# include			<Texture.hh>
# include			"IEntity.hpp"

template<class T>
class				AEntity : public IEntity<T>
{
public:
  AEntity(double x = 0, double y = 0);
  virtual double		getPosX() const; 
  virtual double		getPosY() const;
  virtual double		getHitboxSize() const;
  virtual bool			isBreakable() const;
  virtual T			getPosition() const;
  virtual T			getRotation() const;
  virtual T			getScale() const;
  virtual float			getSpeed() const;

  virtual void			setPosX(double x);
  virtual void			setPosY(double y);
  virtual void			setHitboxSize(double hitbox);
  virtual void			setIsBreakable(bool breakable);
  virtual void			setPosition(const T &pos);
  virtual void			setRotation(const T &pos);
  virtual void			setScale(const T &pos);
  virtual void			setSpeed(float speed);
  virtual void			setIsDraw(bool isDraw);

  virtual IEntity<T>		*clone(double x, double y) = 0;
  virtual eEntityType		getType() const = 0;
  virtual bool			isDraw() const;
private:
  double			_x;
  double			_y;
  double				_hitboxSize;
  bool				_isBreakable;
  T				_position;
  T				_rotation;
  T				_scale;
  float				_speed;
  bool				_isDraw;
};

template <class T>
AEntity<T>::AEntity(double x, double y)
{
  this->_x = x;
  this->_y = y;
  this->_isDraw = false;
}

template <class T>
bool				AEntity<T>::isDraw() const
{
  return (_isDraw);
}

template <class T>
void				AEntity<T>::setIsDraw(bool isDraw) 
{
  _isDraw = isDraw;
}


template <class T>
void				AEntity<T>::setHitboxSize(double hitbox)
{
  _hitboxSize = hitbox;
}

template <class T>
void				AEntity<T>::setIsBreakable(bool breakable)
{
  _isBreakable = breakable;
}

template <class T> 
void				AEntity<T>::setPosition(const T &pos)
{
  _position = pos;
}

template <class T>
void				AEntity<T>::setRotation(const T &pos)
{
  _rotation = pos;
}

template <class T>
void				AEntity<T>::setScale(const T &pos)
{
  _scale = pos;
}

template <class T>
double				AEntity<T>::getHitboxSize() const
{
  return (_hitboxSize);
}

template <class T>
bool				AEntity<T>::isBreakable() const
{
  return (_isBreakable);
}

template <class T>
T				AEntity<T>::getPosition() const
{
  return (_position);
}

template <class T>
T				AEntity<T>::getRotation() const
{
  return (_rotation);
}

template <class T>
T				AEntity<T>::getScale() const
{
  return (_scale);
}

template <class T>
double				AEntity<T>::getPosX() const
{
  return (_x);
}

template <class T>
double				AEntity<T>::getPosY() const
{
  return (_y);
}

template <class T>
float				AEntity<T>::getSpeed() const
{
  return (_speed);
}

template <class T>
void				AEntity<T>::setPosX(double x)
{
  this->_x = x;
}

template <class T>
void				AEntity<T>::setPosY(double y)
{
  this->_y = y;
}

template <class T>
void				AEntity<T>::setSpeed(float speed)
{
  this->_speed = speed;
}

#endif				/* AENTITY_HPP_ */
