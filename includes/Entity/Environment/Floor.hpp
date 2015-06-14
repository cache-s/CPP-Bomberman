#ifndef				FLOOR_HPP_
# define			FLOOR_HPP_

# include			"IFloor.hpp"

template <class T>
class				Floor : public IFloor<T>
{
public:
  Floor(double x = 0, double y = 0);
  ~Floor();
  Floor(Floor const& other);
  IEntity<T>			*clone(double x, double y);
  eEntityType			getType() const;
private:
};

template <class T>
IEntity<T>			*Floor<T>::clone(double x, double y)
{
  Floor<T> *floor = new Floor<T>(*this);
  floor->setPosX(x);
  floor->setPosY(y);
  floor->setScale(T(10, 10, 10));
  floor->setPosition(T(x, 0, y));
  floor->setRotation(T(0, 0, 0));
  floor->setIsBreakable(false);
  floor->setIsCrossable(true);
   return (floor);
}

template <class T>
Floor<T>::Floor(Floor const&other)
{
  this->setPosX(other.getPosX());
  this->setPosY(other.getPosY());
  this->setHitboxSize(other.getHitboxSize());
  this->setIsBreakable(other.isBreakable());
  this->setPosition(other.getPosition());
  this->setRotation(other.getRotation());
  this->setScale(other.getScale());
  this->setIsCrossable(true);
}

template <class T>
Floor<T>::Floor(double x, double y)
{
  this->setPosX(x);
  this->setPosY(y);
  this->setScale(T(10, 10, 10));
  this->setPosition(T(x, 0, y));
  this->setRotation(T(0, 0, 0));
  this->setIsBreakable(true);
  this->setIsCrossable(true);
}

template <class T>
eEntityType			Floor<T>::getType() const
{
  return (FLOOR);
}

template <class T>
Floor<T>::~Floor()
{
}

#endif			//FLOOR_HPP_
