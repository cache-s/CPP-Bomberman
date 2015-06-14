#ifndef				MONSTER_HPP_
# define			MONSTER_HPP_

# include			"IMonster.hpp"

template <typename T>
class				Monster : public IMonster<T>
{
public:
  Monster(double x = 0, double y = 0);
  ~Monster();
  Monster(Monster const &other);
  IEntity<T>	*clone(double x, double y);
  eEntityType   getType() const;
};

template <typename T>
Monster<T>::Monster(double x, double y)
{
  this->setPosX(x);
  this->setPosY(y);
  this->setIsBreakable(true);
}

template <typename T>
eEntityType			Monster<T>::getType() const
{
  return (MONSTER);
}

template <typename T>
Monster<T>::~Monster()
{
}

template <typename T>
IEntity<T>				*Monster<T>::clone(double x, double y)
{
  Monster<T> *monster = new Monster<T>(*this);
  monster->setPosX(x);
  monster->setPosY(y);
  return (monster);
}

template <typename T>
Monster<T>::Monster(Monster const &other)
{
  this->setPosX(other.getPosX());
  this->setPosY(other.getPosY());
  this->setHitboxSize(other.getHitboxSize());
  this->setIsBreakable(other.isBreakable());
  this->setPosition(other.getPosition());
  this->setRotation(other.getRotation());
  this->setScale(other.getScale());
}

#endif				//MONSTER_HPP_
