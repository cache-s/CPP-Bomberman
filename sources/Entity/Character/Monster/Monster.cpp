#include			"Monster.hpp"

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
