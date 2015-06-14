//
// Speed.hpp for bomberman in /home/chazot_a/rendu/cpp_bomberman
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Sun Jun 14 21:33:29 2015 Jordan Chazottes
// Last update Sun Jun 14 21:33:30 2015 Jordan Chazottes
//

#ifndef				SPEED_HPP_
# define			SPEED_HPP_

# include			"IBonus.hpp"

template <typename T>
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

template <typename T>
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

template <typename T>
eEntityType			Speed<T>::getType() const
{
  return (BSPEED);
}

template <typename T>
Speed<T>::~Speed()
{
}

template <typename T>
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

template <typename T>
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
