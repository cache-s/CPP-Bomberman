//
// MapWall.hpp for bomberman in /home/chazot_a/rendu/cpp_bomberman
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Sun Jun 14 21:33:10 2015 Jordan Chazottes
// Last update Sun Jun 14 21:33:11 2015 Jordan Chazottes
//

#ifndef					MAPWALL_HPP_
# define				MAPWALL_HPP_

# include				"IWall.hpp"

template <typename T>
class					MapWall : public IWall<T>
{
public:
  MapWall(double x = 0, double y = 0);
  ~MapWall();
  MapWall(MapWall const &other);
  IEntity<T>				*clone(double x, double y);
  eEntityType				getType() const;
private:
};

template <typename T>
IEntity<T>				*MapWall<T>::clone(double x, double y)
{
  MapWall<T> *brkwall = new MapWall<T>(*this);
  brkwall->setPosX(x);
  brkwall->setPosY(y);
  brkwall->setScale(T(10, 10, 10));
  brkwall->setPosition(T(x, 0, y));
  brkwall->setRotation(T(0, 0, 0));
  brkwall->setIsBreakable(false);
  brkwall->setHitboxSize(1);
  brkwall->setIsCrossable(false);
  return (brkwall);
}

template <typename T>
MapWall<T>::MapWall(MapWall const &other)
{
  this->setPosX(other.getPosX());
  this->setPosY(other.getPosY());
  this->setHitboxSize(other.getHitboxSize());
  this->setIsBreakable(other.isBreakable());
  this->setPosition(other.getPosition());
  this->setRotation(other.getRotation());
  this->setScale(other.getScale());
  this->setIsCrossable(false);
}

template <typename T>
MapWall<T>::MapWall(double x, double y)
{
  this->setPosX(x);
  this->setPosY(y);
  this->setScale(T(10, 10, 10));
  this->setPosition(T(x, 0, y));
  this->setRotation(T(0, 0, 0));
  this->setHitboxSize(1);
  this->setIsBreakable(false);
  this->setIsCrossable(false);
}

template <typename T>
eEntityType			MapWall<T>::getType() const
{
  return (MAPWALL);
}

template <typename T>
MapWall<T>::~MapWall()
{
}

#endif					/* MAPWALL_HPP_ */
