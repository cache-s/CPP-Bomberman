#ifndef				UBRKWALL_HPP_
# define			UBRKWALL_HPP_

# include			"IWall.hpp"

template <class T>
class				UbrkWall : public IWall<T>
{
public:
  UbrkWall(int x = 0, int y = 0);
  ~UbrkWall();
  UbrkWall(UbrkWall const &other);
  IEntity<T>			*clone(int x, int y);
  eEntityType			getType() const;
private:
};

template <class T>
UbrkWall<T>::UbrkWall(int x, int y)
{
  this->setPosX(x);
  this->setPosY(y);
  this->setIsBreakable(false);
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
IEntity<T>				*UbrkWall<T>::clone(int x, int y)
{
  UbrkWall<T> *ubrkWall = new UbrkWall<T>(*this);
  ubrkWall->setPosX(x);
  ubrkWall->setPosY(y);
  return (ubrkWall);
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
