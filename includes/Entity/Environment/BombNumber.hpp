#ifndef				BOMBNUMBER_HPP_
# define			BOMBNUMBER_HPP_

# include			"IBonus.hpp"

template <class T>
class				BombNumber : public IBonus<T>
{
public:
  BombNumber();
  ~BombNumber();
  BombNumber(BombNumber const &other);
  IEntity<T>			*clone();
  eEntityType			getType() const;
private:
};

template <class T>
BombNumber<T>::BombNumber()
{
}

template <class T>
IEntity<T>				*BombNumber<T>::clone()
{
  return (new BombNumber<T>(*this));
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
  return (BOMBNUMBER);
}

template <class T>
BombNumber<T>::~BombNumber()
{
}

#endif				/* BOMBNUMBER_HPP__ */
