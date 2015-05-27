#ifndef					BRKWALL_HPP_
# define				BRKWALL_HPP_

# include				"IWall.hpp"

template <class T>
class					BrkWall : public IWall<T>
{
public:
  BrkWall();
  ~BrkWall();
  BrkWall(BrkWall const &other);
  IEntity<T>				*clone();
  eEntityType				getType() const;
private:
};

template <class T>
IEntity<T>				*BrkWall<T>::clone()
{
  return (new BrkWall<T>(*this));
}

template <class T>
BrkWall<T>::BrkWall(BrkWall const &other)
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
BrkWall<T>::BrkWall()
{
}

template <class T>
eEntityType			BrkWall<T>::getType() const
{
  return (BRKWALL);
}

template <class T>
BrkWall<T>::~BrkWall()
{
}

#endif					/* BRKWALL_HPP_ */
