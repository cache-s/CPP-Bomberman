#ifndef				BOMBNUMBER_HPP_
# define			BOMBNUMBER_HPP_

# include			"IBonus.hpp"

template <class T>
class				BombNumber : public IBonus<T>
{
public:
  BombNumber(int x = 0, int y = 0);
  ~BombNumber();
  BombNumber(BombNumber const &other);
  IEntity<T>			*clone(int x, int y);
  eEntityType			getType() const;
private:
};

template <class T>
BombNumber<T>::BombNumber(int x, int y)
{
  this->setPosX(x);
  this->setPosY(y);
  this->setIsBreakable(true);
}

template <class T>
IEntity<T>				*BombNumber<T>::clone(int x, int y)
{
  BombNumber<T> *bomb = new BombNumber<T>(*this);
  bomb->setPosX(x);
  bomb->setPosY(y);
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
