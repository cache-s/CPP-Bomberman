#ifndef					MAPWALL_HPP_
# define				MAPWALL_HPP_

# include				"IWall.hpp"

template <class T>
class					MapWall : public IWall<T>
{
public:
  MapWall(int x = 0, int y = 0);
  ~MapWall();
  MapWall(MapWall const &other);
  IEntity<T>				*clone(int x, int y);
  eEntityType				getType() const;
private:
};

template <class T>
IEntity<T>				*MapWall<T>::clone(int x, int y)
{
  MapWall<T> *brkwall = new MapWall<T>(*this);
  brkwall->setPosX(x);
  brkwall->setPosY(y);
  brkwall->setScale(T(10, 10, 10));
  brkwall->setPosition(T(x, 0, y));
  brkwall->setRotation(T(0, 0, 0));
  brkwall->setIsBreakable(false);
  brkwall->setHitboxSize(1);
  return (brkwall);
}

template <class T>
MapWall<T>::MapWall(MapWall const &other)
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
MapWall<T>::MapWall(int x, int y)
{
  this->setPosX(x);
  this->setPosY(y);
  this->setScale(T(10, 10, 10));
  this->setPosition(T(x, 0, y));
  this->setRotation(T(0, 0, 0));
  this->setIsBreakable(false);
}

template <class T>
eEntityType			MapWall<T>::getType() const
{
  return (MAPWALL);
}

template <class T>
MapWall<T>::~MapWall()
{
}

#endif					/* MAPWALL_HPP_ */
