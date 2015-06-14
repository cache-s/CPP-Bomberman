#ifndef				FLAME_HPP_
# define			FLAME_HPP_

#include			"IFlame.hpp"

template <typename T>
class				Flame : public IFlame<T>
{
public:
  Flame(double x = 0, double y = 0);
  ~Flame();
  Flame(Flame const &other);
  IEntity<T>		*clone(double x, double y);
  eEntityType		getType() const;
  bool			isDrop() const;
  void			setDrop(bool drop);
private:
  bool			_drop;
};

template<typename T>
void		Flame<T>::setDrop(bool drop)
{
  _drop = drop;
}

template<typename T>
bool		Flame<T>::isDrop() const
{
  return (_drop);
}

template <typename T>
Flame<T>::Flame(double x, double y)
{
  this->setPosX(x);
  this->setPosY(y);
  this->setScale(T(10, 10, 10));
  this->setPosition(T(x, 0, y));
  this->setRotation(T(0, 0, 0));
  this->setHitboxSize(1);
  this->setIsBreakable(false);
  this->setIsCrossable(true);
  _drop = false;
}

template <typename T>
eEntityType			Flame<T>::getType() const
{
  return (FLAME);
}

template <typename T>
Flame<T>::~Flame()
{
}

template <typename T>
IEntity<T>				*Flame<T>::clone(double x, double y)
{
  Flame<T> *flame = new Flame<T>(*this);
  flame->setPosX(x);
  flame->setPosY(y);
  flame->setScale(T(10, 10, 10));
  flame->setPosition(T(x, 0, y));
  flame->setRotation(T(0, 0, 0));
  flame->setIsBreakable(false);
  flame->setHitboxSize(1);
  flame->_drop = false;
  flame->setIsCrossable(true);
  return (flame);
}

template <typename T>
Flame<T>::Flame(Flame const &other)
{
  this->setPosX(other.getPosX());
  this->setPosY(other.getPosY());
  this->setHitboxSize(other.getHitboxSize());
  this->setIsBreakable(other.isBreakable());
  this->setPosition(other.getPosition());
  this->setRotation(other.getRotation());
  this->setScale(other.getScale());
  this->setIsCrossable(true);
  _drop = other._drop;
}

#endif				/* FLAME_HPP_ */
