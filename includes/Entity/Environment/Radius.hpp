//
// Radius.hpp for bomberman in /home/chazot_a/rendu/cpp_bomberman
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Sun Jun 14 21:33:25 2015 Jordan Chazottes
// Last update Sun Jun 14 21:33:26 2015 Jordan Chazottes
//

#ifndef				RADIUS_HPP_
# define			RADIUS_HPP_

# include			"IBonus.hpp"

template <typename T>
class				Radius : public IBonus<T>
{
public:
  Radius(double x = 0, double y = 0);
  ~Radius();
  Radius(Radius const &other);
  IEntity<T>			*clone(double x, double y);
  eEntityType			getType() const;
private:
};

template <typename T>
Radius<T>::Radius(double x, double y)
{
  this->setPosX(x);
  this->setPosY(y);
  this->setIsBreakable(true);
  this->setScale(T(10, 10, 10));
  this->setPosition(T(x, 0, y));
  this->setRotation(T(0, 0, 0));
  this->setIsCrossable(true);
  this->setHitboxSize(1);
}

template <typename T>
eEntityType			Radius<T>::getType() const
{
  return (BRADIUS);
}

template <typename T>
Radius<T>::~Radius()
{
}

template <typename T>
IEntity<T>				*Radius<T>::clone(double x, double y)
{
  Radius<T> *radius = new Radius<T>(*this);
  radius->setPosX(x);
  radius->setPosY(y);
  radius->setScale(T(10, 10, 10));
  radius->setPosition(T(x, 0, y));
  radius->setRotation(T(0, 0, 0));
  radius->setIsBreakable(true);
  radius->setIsCrossable(true);
  return (radius);
}

template <typename T>
Radius<T>::Radius(Radius const &other)
{
  this->setPosX(other.getPosX());
  this->setPosY(other.getPosY());
  this->setHitboxSize(other.getHitboxSize());
  this->setIsBreakable(other.isBreakable());
  this->setPosition(other.getPosition());
  this->setRotation(other.getRotation());
  this->setScale(other.getScale());
  this->setIsCrossable(true);
}

#endif				/* RADIUS_HPP_ */
