#ifndef				BOMBNUMBER_HPP_
# define			BOMBNUMBER_HPP_

# include			"IBonus.hpp"

template <class T>
class				BombNumber : public IBonus<T>
{
public:
  BombNumber(double x = 0, double y = 0);
  ~BombNumber();
  BombNumber(BombNumber const &other);
  IEntity<T>			*clone(double x, double y);
  eEntityType			getType() const;
private:
};

template <class T>
BombNumber<T>::BombNumber(double x, double y)
{
  this->setPosX(x);
  this->setPosY(y);
  this->setScale(T(10, 10, 10));
  this->setPosition(T(x, 0, y));
  this->setRotation(T(0, 0, 0));
  this->setHitboxSize(1);
  this->setIsBreakable(true);
}

template <class T>
IEntity<T>				*BombNumber<T>::clone(double x, double y)
{
  BombNumber<T> *bomb = new BombNumber<T>(*this);
  bomb->setPosX(x);
  bomb->setPosY(y);
  bomb->setScale(T(10, 10, 10));
  bomb->setPosition(T(x, 0, y));
  bomb->setRotation(T(0, 0, 0));
  bomb->setIsBreakable(false);
  bomb->setHitboxSize(1);
  return (bomb);
}

template <class T>
BombNumber<T>::BombNumber(BombNumber const &other)
{
  this->setPosX(other.getPosX());
  this->setPosY(other.getPosY());
  this->setHitboxSize(other.getHitboxSize());
  this->setIsBreakable(other.isBreakable());
  this->setPosition(other.getPosition());
  this->setRotation(other.getRotation());
  this->setScale(other.getScale());
}

template <class T>
eEntityType			BombNumber<T>::getType() const
{
  return (BBOMBNUMBER);
}

template <class T>
BombNumber<T>::~BombNumber()
{
}

#endif				/* BOMBNUMBER_HPP__ */
