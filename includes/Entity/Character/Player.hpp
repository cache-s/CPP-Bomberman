#ifndef				PLAYER_HPP_
# define			PLAYER_HPP_

# include			"IPlayer.hpp"

template <class T>
class				Player : public IPlayer<T>
{
public:
  Player();
  Player(Player const &other);
  ~Player();
  IEntity<T>			*clone();
  eEntityType			getType() const;
};

template <class T>
Player<T>::Player()
{

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
IEntity<T>				*Player<T>::clone()
{
  return (new Player<T>(*this));
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
