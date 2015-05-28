#ifndef				FLAME_HPP_
# define			FLAME_HPP_

#include			"IFlame.hpp"

template <class T>
class				Flame : public IFlame<T>
{
public:
  Flame(int x = 0, int y = 0);
  ~Flame();
  Flame(Flame const &other);
  IEntity<T>		*clone(int x, int y);
  eEntityType		getType() const;
private:
};

template <class T>
Flame<T>::Flame(int x, int y)
{
  this->setPosX(x);
  this->setPosY(y);
  this->setIsBreakable(false);
}

template <class T>
eEntityType			Flame<T>::getType() const
{
  return (FLAME);
}

template <class T>
Flame<T>::~Flame()
{
}

template <class T>
IEntity<T>				*Flame<T>::clone(int x, int y)
{
  Flame<T> *flame = new Flame<T>(*this);
  flame->setPosX(x);
  flame->setPosY(y);
  return (flame);
}

template <class T>
Flame<T>::Flame(Flame const &other)
{
  this->setPosX(other.getPosX());
  this->setPosY(other.getPosY());
  this->setHitboxSize(other.getHitboxSize());
  this->setIsBreakable(other.isBreakable());
  this->setPosition(other.getPosition());
  this->setRotation(other.getRotation());
  this->setScale(other.getScale());
}

#endif				/* FLAME_HPP_ */
