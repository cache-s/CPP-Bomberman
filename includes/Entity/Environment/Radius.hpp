#ifndef				RADIUS_HPP_
# define			RADIUS_HPP_

# include			"IBonus.hpp"

template <class T>
class				Radius : public IBonus<T>
{
public:
  Radius();
  ~Radius();
  Radius(Radius const &other);
  IEntity<T>			*clone();
  eEntityType			getType() const;
private:
};

template <class T>
Radius<T>::Radius()
{
}

template <class T>
eEntityType			Radius<T>::getType() const
{
  return (RADIUS);
}

template <class T>
Radius<T>::~Radius()
{
}

template <class T>
IEntity<T>				*Radius<T>::clone()
{
  return (new Radius<T>(*this));
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
