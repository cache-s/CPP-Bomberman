#ifndef				MONSTER_HPP_
# define			MONSTER_HPP_

# include			"IMonster.hpp"

template <class T>
class				Monster : public IMonster<T>
{
public:
  Monster(int x = 0, int y = 0);
  ~Monster();
  Monster(Monster const &other);
  IEntity<T>	*clone(int x, int y);
  eEntityType   getType() const;
};

template <class T>
Monster<T>::Monster(int x, int y)
{
  this->setPosX(x);
  this->setPosY(y);
  this->setIsBreakable(true);
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
IEntity<T>				*Monster<T>::clone(int x, int y)
{
  Monster<T> *monster = new Monster<T>(*this);
  monster->setPosX(x);
  monster->setPosY(y);
  return (monster);
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
