#ifndef				AENTITY_HPP_
# define			AENTITY_HPP_

# include			<Texture.hh>
# include			"IEntity.hpp"

template<typename T>
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
  virtual bool			isCrossable() const;

  virtual void			setPosX(double x);
  virtual void			setPosY(double y);
  virtual void			setHitboxSize(double hitbox);
  virtual void			setIsBreakable(bool breakable);
  virtual void			setPosition(const T &pos);
  virtual void			setRotation(const T &pos);
  virtual void			setScale(const T &pos);
  virtual void			setSpeed(float speed);
  virtual void			setIsDraw(bool isDraw);
  virtual void			setIsCrossable(bool isCrossable);

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
  bool				_isCrossable;
};

template <typename T>
AEntity<T>::AEntity(double x, double y)
{
  this->_x = x;
  this->_y = y;
  this->_isDraw = false;
}

template <typename T>
bool				AEntity<T>::isDraw() const
{
  return (_isDraw);
}

template <typename T>
void				AEntity<T>::setIsDraw(bool isDraw) 
{
  _isDraw = isDraw;
}

template <typename T>
bool				AEntity<T>::isCrossable() const
{
  return (_isCrossable);
}

template <typename T>
void				AEntity<T>::setIsCrossable(bool isCrossable) 
{
  _isCrossable = isCrossable;
}


template <typename T>
void				AEntity<T>::setHitboxSize(double hitbox)
{
  _hitboxSize = hitbox;
}

template <typename T>
void				AEntity<T>::setIsBreakable(bool breakable)
{
  _isBreakable = breakable;
}

template <typename T> 
void				AEntity<T>::setPosition(const T &pos)
{
  _position = pos;
}

template <typename T>
void				AEntity<T>::setRotation(const T &pos)
{
  _rotation = pos;
}

template <typename T>
void				AEntity<T>::setScale(const T &pos)
{
  _scale = pos;
}

template <typename T>
double				AEntity<T>::getHitboxSize() const
{
  return (_hitboxSize);
}

template <typename T>
bool				AEntity<T>::isBreakable() const
{
  return (_isBreakable);
}

template <typename T>
T				AEntity<T>::getPosition() const
{
  return (_position);
}

template <typename T>
T				AEntity<T>::getRotation() const
{
  return (_rotation);
}

template <typename T>
T				AEntity<T>::getScale() const
{
  return (_scale);
}

template <typename T>
double				AEntity<T>::getPosX() const
{
  return (_x);
}

template <typename T>
double				AEntity<T>::getPosY() const
{
  return (_y);
}

template <typename T>
float				AEntity<T>::getSpeed() const
{
  return (_speed);
}

template <typename T>
void				AEntity<T>::setPosX(double x)
{
  this->_x = x;
}

template <typename T>
void				AEntity<T>::setPosY(double y)
{
  this->_y = y;
}

template <typename T>
void				AEntity<T>::setSpeed(float speed)
{
  this->_speed = speed;
}

#endif				/* AENTITY_HPP_ */
