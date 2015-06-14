#ifndef				SPEED_HPP_
# define			SPEED_HPP_

# include			"IBonus.hpp"

template <class T>
class				Speed : public IBonus<T>
{
public:
  Speed(double x = 0, double y = 0);
  ~Speed();
  Speed(Speed const &other);
  IEntity<T>			*clone(double x, double y);
  eEntityType			getType() const;
private:
};

template <class T>
Speed<T>::Speed(double x, double y)
{
  this->setPosX(x);
  this->setPosY(y);
  this->setScale(T(10, 10, 10));
  this->setPosition(T(x, 0, y));
  this->setRotation(T(0, 0, 0));
  this->setHitboxSize(1);
  this->setIsBreakable(true);
  this->setIsCrossable(true);
}

template <class T>
eEntityType			Speed<T>::getType() const
{
  return (BSPEED);
}

template <class T>
Speed<T>::~Speed()
{
}

template <class T>
IEntity<T>				*Speed<T>::clone(double x, double y)
{
  Speed<T> *speed = new Speed<T>(*this);
  speed->setPosX(x);
  speed->setPosY(y);
  speed->setScale(T(10, 10, 10));
  speed->setPosition(T(x, 0, y));
  speed->setRotation(T(0, 0, 0));
  speed->setIsBreakable(true);
  speed->setHitboxSize(1);
  speed->setIsCrossable(true);
  return (speed);
}

template <class T>
Speed<T>::Speed(Speed const &other)
{
  this->setPosX(other.getPosX());
  this->setPosY(other.getPosY());
  this->setHitboxSize(other.getHitboxSize());
  this->setIsBreakable(other.isBreakable());
  this->setPosition(other.getPosition());
  this->setRotation(other.getRotation());
  this->setScale(other.getScale());
  this->setIsCrossable(other.isCrossable());
}

#endif				/* SPEED_HPP_ */
