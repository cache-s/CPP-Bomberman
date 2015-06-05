#ifndef					BRKWALL_HPP_
# define				BRKWALL_HPP_

# include				"IWall.hpp"

template <class T>
class					BrkWall : public IWall<T>
{
public:
  BrkWall(int x = 0, int y = 0);
  ~BrkWall();
  BrkWall(BrkWall const &other);
  IEntity<T>				*clone(int x, int y);
  eEntityType				getType() const;
private:
};

template <class T>
IEntity<T>				*BrkWall<T>::clone(int x, int y)
{
  BrkWall<T> *brkwall = new BrkWall<T>(*this);
  (void)x;(void)y;
  brkwall->setPosX(0);
  brkwall->setPosY(0);
  brkwall->setScale(T(10, 10, 10));
  brkwall->setPosition(T(0, 0, 0));
  brkwall->setRotation(T(0, 0, 0));
  brkwall->setIsBreakable(false);
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
BrkWall<T>::BrkWall(int x, int y)
{
  (void)x;(void)y;
  this->setPosX(0);
  this->setPosY(0);
  this->setScale(T(10, 10, 10));
  this->setPosition(T(0, 0, 0));
  this->setRotation(T(0, 0, 0));
  this->setIsBreakable(true);
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
