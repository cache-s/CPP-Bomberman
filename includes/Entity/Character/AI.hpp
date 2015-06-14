#ifndef				AI_HPP_
# define			AI_HPP_

# include			"IAI.hpp"

template <typename T>
class				AI : public IAI<T>
{
public:
  AI(double x = 0, double y = 0);
  ~AI();
  AI(AI const &other);
  IEntity<T>			*clone(double x, double y);
  eEntityType			getType() const;
};

template <typename T>
AI<T>::AI(double x, double y)
{
  this->setPosX(x);
  this->setPosY(y);
  this->setIsBreakable(false);
  this->setHitboxSize(0.5);  
}

template <typename T>
eEntityType			AI<T>::getType() const
{
  return (ARTINT);
}

template <typename T>
IEntity<T>				*AI<T>::clone(double x, double y)
{
  AI<T> *ai = new AI<T>(*this);
  ai->setPosX(x);
  ai->setPosY(y);
  return (ai);
}

template <typename T>
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

template <typename T>
AI<T>::~AI()
{
}

#endif				//AI_HPP_
