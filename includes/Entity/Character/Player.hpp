#ifndef				PLAYER_HPP_
# define			PLAYER_HPP_

# include			"IPlayer.hpp"

template <class T>
class				Player : public IPlayer<T>
{
public:
  Player(double x = 0, double y = 0);
  Player(Player const &other);
  ~Player();
  IEntity<T>			*clone(double x, double y);
  eEntityType			getType() const;
  int				getBombStock() const;
  void				setBombStock(int nb);
  int				getRadius() const;
  void				setRadius(int nb);
private:
  int				_bombStock;
  int				_radius;
};

template <class T>
Player<T>::Player(double x, double y) : _bombStock(1), _radius(2)
{
  this->setPosX(x);
  this->setPosY(y);
  this->setScale(T(0.020, 0.020, 0.020));
  this->setPosition(T(x, 0, y));
  this->setRotation(T(0, 180, 0));
  this->setIsBreakable(true);
  this->setHitboxSize(0.2);
  this->setSpeed(1.0f);
}

template <class T>
Player<T>::Player(Player const &other) : _bombStock(other._bombStock), _radius(other._radius)
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
IEntity<T>				*Player<T>::clone(double x, double y)
{
  Player<T> *player = new Player<T>(*this);

  player->setPosX(x);
  player->setPosY(y);
  player->setScale(T(0.020, 0.020, 0.020));
  player->setPosition(T(x, 0, y));
  player->setRotation(T(0, 180, 0));
  player->setIsBreakable(true);
  player->setSpeed(1.0f);
  player->setHitboxSize(0.2);
  player->_bombStock = 1;
  player->_radius = 2;
  return (player);
}

template <class T>
int		Player<T>::getBombStock() const
{
  return (_bombStock);
}

template <class T>
void		Player<T>::setBombStock(int nb)
{
  _bombStock = nb;
}

template <class T>
int		Player<T>::getRadius() const
{
  return (_radius);
}

template <class T>
void		Player<T>::setRadius(int nb)
{
  _radius = nb;
}

#endif				//PLAYER_HPP_
