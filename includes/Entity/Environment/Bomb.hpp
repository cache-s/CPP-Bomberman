#ifndef				BOMB_HPP_
# define			BOMB_HPP_

#include			"IBomb.hpp"

template <class T>
class				Bomb : public IBomb<T>
{
public:
  Bomb(int x = 0, int y = 0);
  ~Bomb();
  Bomb(Bomb const &other);
  IEntity<T>			*clone(int x, int y);
  eEntityType			getType() const;
private:
};

template <class T>
IEntity<T>				*Bomb<T>::clone(int x, int y)
{
  Bomb<T> *bomb = new Bomb<T>(*this);
  bomb->setPosX(x);
  bomb->setPosY(y);
  return (bomb);
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
Bomb<T>::Bomb(int x, int y)
{
  this->setPosX(x);
  this->setPosY(y);
  this->setIsBreakable(true);
  this->setScale(glm::vec3(10, 10, 10));
  this->setPosition(T(x, y, 0));

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
