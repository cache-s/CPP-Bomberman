#ifndef				RADIUS_HPP_
# define			RADIUS_HPP_

# include			"IBonus.hpp"

template <class T>
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

template <class T>
Radius<T>::Radius(double x, double y)
{
  this->setPosX(x);
  this->setPosY(y);
  this->setIsBreakable(true);
}

template <class T>
eEntityType			Radius<T>::getType() const
{
  return (BRADIUS);
}

template <class T>
Radius<T>::~Radius()
{
}

template <class T>
IEntity<T>				*Radius<T>::clone(double x, double y)
{
  Radius<T> *radius = new Radius<T>(*this);
  radius->setPosX(x);
  radius->setPosY(y);
  radius->setScale(T(10, 10, 10));
  radius->setPosition(T(x, 0, y));
  radius->setRotation(T(0, 0, 0));
  radius->setIsBreakable(false);
  return (radius);
}

template <class T>
Radius<T>::Radius(Radius const &other)
{
  this->setPosX(other.getPosX());
  this->setPosY(other.getPosY());
  this->setHitboxSize(other.getHitboxSize());
  this->setIsBreakable(other.isBreakable());
  this->setPosition(other.getPosition());
  this->setRotation(other.getRotation());
  this->setScale(other.getScale());
}

#endif				/* RADIUS_HPP_ */
