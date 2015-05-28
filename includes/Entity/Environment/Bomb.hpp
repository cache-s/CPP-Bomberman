#ifndef				BOMB_HPP_
# define			BOMB_HPP_

#include			"IBomb.hpp"

template <class T>
class				Bomb : public IBomb<T>
{
public:
  Bomb();
  ~Bomb();
  Bomb(Bomb const &other);
  IEntity<T>			*clone();
  eEntityType			getType() const;
private:
};

template <class T>
IEntity<T>				*Bomb<T>::clone()
{
  return (new Bomb<T>(*this));
}

template <class T>
Bomb<T>::Bomb(Bomb const &other)
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
Bomb<T>::Bomb()
{
  std::cout << "i am a bomb lol" << std::endl;
}

template <class T>
eEntityType			Bomb<T>::getType() const
{
  return (BOMB);
}

template <class T>
Bomb<T>::~Bomb()
{
}

#endif				/* BOMB_HPP_ */
