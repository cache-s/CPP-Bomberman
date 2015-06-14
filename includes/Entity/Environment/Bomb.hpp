#ifndef				BOMB_HPP_
# define			BOMB_HPP_

#include			"IBomb.hpp"

template <class T>
class				Bomb : public IBomb<T>
{
public:
  Bomb(double x = 0, double y = 0);
  ~Bomb();
  Bomb(Bomb const &other);
  IEntity<T>			*clone(double x, double y);
  eEntityType			getType() const;
  int                           getRadius() const;
  void                          setRadius(int nb);
private:
  int				_radius;
};

template <class T>
IEntity<T>				*Bomb<T>::clone(double x, double y)
{
  Bomb<T> *bomb = new Bomb<T>(*this);
  bomb->setPosX(x);
  bomb->setPosY(y);
  bomb->setScale(T(10, 10, 10));
  bomb->setPosition(T(x, 0, y));
  bomb->setRotation(T(0, 0, 0));
  bomb->setIsBreakable(false);
  bomb->setIsCrossable(false);
  bomb->setHitboxSize(1);
  return (bomb);

}

template <class T>
Bomb<T>::Bomb(Bomb const &other)
{
  this->setPosX(other.getPosX());
  this->setPosY(other.getPosY());
  this->setHitboxSize(other.getHitboxSize());
  this->setIsBreakable(other.isBreakable());
  this->setPosition(other.getPosition());
  this->setRotation(other.getRotation());
  this->setScale(other.getScale());
  this->setIsCrossable(false);
}

template <class T>
Bomb<T>::Bomb(double x, double y)
{
  this->setPosX(x);
  this->setPosY(y);
  this->setScale(T(10, 10, 10));
  this->setPosition(T(x, 0, y));
  this->setRotation(T(0, 0, 0));
  this->setIsBreakable(false);
  this->setHitboxSize(1);
  this->setIsCrossable(false);
}

template <class T>
eEntityType			Bomb<T>::getType() const
{
  return (BOMB);
}

template <class T>
Bomb<T>::~Bomb()
{
}

template <class T>
int             Bomb<T>::getRadius() const
{
  return (_radius);
}

template <class T>
void            Bomb<T>::setRadius(int nb)
{
  _radius = nb;
}

#endif				/* BOMB_HPP_ */
