#ifndef				AI_HPP_
# define			AI_HPP_

# include			"IAI.hpp"

template <class T>
class				AI : public IAI<T>
{
public:
  AI();
  ~AI();
  AI(AI const &other);
  IEntity<T>			*clone();
  eEntityType			getType() const;
};

template <class T>
AI<T>::AI()
{
}

template <class T>
eEntityType			AI<T>::getType() const
{
  return (ARTINT);
}

template <class T>
IEntity<T>				*AI<T>::clone()
{
  return (new AI<T>(*this));
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
