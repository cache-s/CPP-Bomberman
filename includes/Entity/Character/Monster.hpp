#ifndef				MONSTER_HPP_
# define			MONSTER_HPP_

# include			"IMonster.hpp"

template <class T>
class				Monster : public IMonster<T>
{
public:
  Monster();
  ~Monster();
  Monster(Monster const &other);
  IEntity<T>	*clone();
  eEntityType   getType() const;
};

template <class T>
Monster<T>::Monster()
{
}

template <class T>
eEntityType			Monster<T>::getType() const
{
  return (MONSTER);
}

template <class T>
Monster<T>::~Monster()
{
}

template <class T>
IEntity<T>				*Monster<T>::clone()
{
  return (new Monster<T>(*this));
}

template <class T>
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
