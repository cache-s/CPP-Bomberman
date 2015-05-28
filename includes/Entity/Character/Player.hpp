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
  this->setPosX(y);
  this->setIsBreakable(true);
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
  return (player);
}

template <class T>
Player<T>::Player(Player const &other)
{
  this->setPosX(other.getPosX());
  this->setPosY(other.getPosY());
  this->setHitboxSize(other.getHitboxSize());
  this->setIsBreakable(other.isBreakable());
  this->setPosition(other.getPosition());
  this->setRotation(other.getRotation());
  this->setScale(other.getScale());
}

#endif				//PLAYER_HPP_
