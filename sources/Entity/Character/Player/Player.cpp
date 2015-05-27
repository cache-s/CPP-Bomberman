#include				"Player.hpp"

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
