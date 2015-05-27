//
// Radius.cpp for  in /home/poupon_d/rendu/cpp_bomberman/sources/Entity/Environment
// 
// Made by delphine poupon
// Login   <poupon_d@epitech.net>
// 
// Started on  Fri May 22 15:28:27 2015 delphine poupon
// Last update Wed May 27 10:44:56 2015 Mathieu Bourmaud
//

#include			"Radius.hpp"

template <class T>
Radius<T>::Radius()
{
}

template <class T>
eEntityType			Radius<T>::getType() const
{
  return (RADIUS);
}

template <class T>
Radius<T>::~Radius()
{
}
