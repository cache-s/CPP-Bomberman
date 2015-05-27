#ifndef				UBRKWALL_HPP_
# define			UBRKWALL_HPP_

# include			"IWall.hpp"

template <class T>
class				UbrkWall : public IWall<T>
{
public:
  UbrkWall();
  ~UbrkWall();
  UbrkWall(UbrkWall const &other);
  IEntity<T>			*clone();
  eEntityType			getType() const;
private:
};

template <class T>
UbrkWall<T>::UbrkWall()
{
}

template <class T>
eEntityType			UbrkWall<T>::getType() const
{
  return (UBRKWALL);
}

template <class T>
UbrkWall<T>::~UbrkWall()
{
}

template <class T>
IEntity<T>				*UbrkWall<T>::clone()
{
  return (new UbrkWall<T>(*this));
}

template <class T>
UbrkWall<T>::UbrkWall(UbrkWall const &other)
{
  this->setPosX(other.getPosX());
  this->setPosY(other.getPosY());
  this->setHitboxSize(other.getHitboxSize());
  this->setIsBreakable(other.isBreakable());
  this->setPosition(other.getPosition());
  this->setRotation(other.getRotation());
  this->setScale(other.getScale());
}

#endif				/* UBRKWALL_HPP_ */
