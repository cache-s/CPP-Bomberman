#ifndef				AI_HPP_
# define			AI_HPP_

# include			"IAI.hpp"

template <class T>
class				AI : public IAI<T>
{
public:
  AI(int x = 0, int y = 0);
  ~AI();
  AI(AI const &other);
  IEntity<T>			*clone(int x, int y);
  eEntityType			getType() const;
};

template <class T>
AI<T>::AI(int x, int y)
{
  this->setPosX(x);
  this->setPosY(y);
  this->setIsBreakable(false);
}

template <class T>
eEntityType			AI<T>::getType() const
{
  return (ARTINT);
}

template <class T>
IEntity<T>				*AI<T>::clone(int x, int y)
{
  AI<T> *ai = new AI<T>(*this);
  ai->setPosX(x);
  ai->setPosY(y);
  return (ai);
}

template <class T>
AI<T>::AI(AI const &other)
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
AI<T>::~AI()
{
}

#endif				//AI_HPP_
