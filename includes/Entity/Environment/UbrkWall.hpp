//
// UbrkWall.hpp for bomberman in /home/chazot_a/rendu/cpp_bomberman
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Sun Jun 14 21:33:33 2015 Jordan Chazottes
// Last update Sun Jun 14 21:33:34 2015 Jordan Chazottes
//

#ifndef				UBRKWALL_HPP_
# define			UBRKWALL_HPP_

# include			"IWall.hpp"

template <typename T>
class				UbrkWall : public IWall<T>
{
public:
  UbrkWall(double x = 0, double y = 0);
  ~UbrkWall();
  UbrkWall(UbrkWall const &other);
  IEntity<T>			*clone(double x, double y);
  eEntityType			getType() const;
private:
};

template <typename T>
UbrkWall<T>::UbrkWall(double x, double y)
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
eEntityType			UbrkWall<T>::getType() const
{
  return (UBRKWALL);
}

template <typename T>
UbrkWall<T>::~UbrkWall()
{
}

template <typename T>
IEntity<T>				*UbrkWall<T>::clone(double x, double y)
{
  UbrkWall<T> *ubrkWall = new UbrkWall<T>(*this);
  ubrkWall->setPosX(x);
  ubrkWall->setPosY(y);
  ubrkWall->setScale(T(10, 10, 10));
  ubrkWall->setPosition(T(x, 0, y));
  ubrkWall->setRotation(T(0, 0, 0));
  ubrkWall->setIsBreakable(false);
  ubrkWall->setHitboxSize(1);
  ubrkWall->setIsCrossable(false);
  return (ubrkWall);
}

template <typename T>
UbrkWall<T>::UbrkWall(UbrkWall const &other)
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

#endif				/* UBRKWALL_HPP_ */
