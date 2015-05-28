#ifndef				SPEED_HPP_
# define			SPEED_HPP_

# include			"IBonus.hpp"

template <class T>
class				Speed : public IBonus<T>
{
public:
  Speed(int x = 0, int y = 0);
  ~Speed();
  Speed(Speed const &other);
  IEntity<T>			*clone(int x, int y);
  eEntityType			getType() const;
private:
};

template <class T>
Speed<T>::Speed(int x, int y)
{
  this->setPosX(x);
  this->setPosY(y);
  this->setIsBreakable(true);
}

template <class T>
eEntityType			Speed<T>::getType() const
{
  return (SPEED);
}

template <class T>
Speed<T>::~Speed()
{
}

template <class T>
IEntity<T>				*Speed<T>::clone(int x, int y)
{
  Speed<T> *speed = new Speed<T>(*this);
  speed->setPosX(x);
  speed->setPosY(y);
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
}

#endif				/* SPEED_HPP_ */
