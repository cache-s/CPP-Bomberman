#ifndef				PLAYER_HPP_
# define			PLAYER_HPP_

# include			"IPlayer.hpp"

template <class T>
class				Player : public IPlayer<T>
{
public:
  Player(int x = 0, int y = 0);
  Player(Player const &other);
  ~Player();
  IEntity<T>			*clone(int x, int y);
  eEntityType			getType() const;
};

template <class T>
Player<T>::Player(int x, int y)
{
  this->setPosX(x);
  this->setPosY(y);
  this->setScale(T(0.05, 0.05, 0.05));
  this->setPosition(T(x, y, 0));
  this->setRotation(T(0, 180, 0));
  this->setIsBreakable(true);
  this->setSpeed(10.0f);
}

template <class T>
eEntityType				Player<T>::getType() const
{
  return (PLAYER);
}

template <class T>
Player<T>::~Player()
{

}

template <class T>
IEntity<T>				*Player<T>::clone(int x, int y)
{
  Player<T> *player = new Player<T>(*this);

  player->setPosX(x);
  player->setPosY(y);
  player->setScale(T(0.05, 0.05, 0.05));
  player->setPosition(T(x, y, 0));
  player->setRotation(T(0, 180, 0));
  player->setIsBreakable(true);
  player->setSpeed(10.0f);
  return (player);
}

template <class T>
Player<T>::Player(Player const &other)
{
  this->setPosX(other.getPosX());
  this->setPosY(other.getPosY());
  this->setScale(other.getScale());
  this->setPosition(other.getPosition());
  this->setRotation(other.getRotation());
  this->setIsBreakable(other.isBreakable());
  this->setHitboxSize(other.getHitboxSize());
  this->setSpeed(other.getSpeed());
}

#endif				//PLAYER_HPP_
