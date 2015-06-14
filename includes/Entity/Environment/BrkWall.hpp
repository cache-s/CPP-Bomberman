#ifndef					BRKWALL_HPP_
# define				BRKWALL_HPP_

# include				"IWall.hpp"

template <class T>
class					BrkWall : public IWall<T>
{
public:
  BrkWall(double x = 0, double y = 0);
  ~BrkWall();
  BrkWall(BrkWall const &other);
  IEntity<T>				*clone(double x, double y);
  eEntityType				getType() const;
private:
};

template <class T>
IEntity<T>				*BrkWall<T>::clone(double x, double y)
{
  BrkWall<T> *brkwall = new BrkWall<T>(*this);
  brkwall->setPosX(x);
  brkwall->setPosY(y);
  brkwall->setScale(T(10, 10, 10));
  brkwall->setPosition(T(x, 0, y));
  brkwall->setRotation(T(0, 0, 0));
  brkwall->setIsBreakable(true);
  brkwall->setHitboxSize(1);
  return (brkwall);
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
BrkWall<T>::BrkWall(double x, double y)
{
  this->setPosX(x);
  this->setPosY(y);
  this->setScale(T(10, 10, 10));
  this->setPosition(T(x, 0, y));
  this->setRotation(T(0, 0, 0));
  this->setIsBreakable(true);
  this->setHitboxSize(1);
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
