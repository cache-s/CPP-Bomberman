//
// Flame.cpp for  in /home/poupon_d/rendu/cpp_bomberman/sources/Entity/Environment
// 
// Made by delphine poupon
// Login   <poupon_d@epitech.net>
// 
// Started on  Fri May 22 15:32:28 2015 delphine poupon
// Last update Wed May 27 10:44:22 2015 Mathieu Bourmaud
//

#include			"Flame.hpp"

template <class T>
Flame<T>::Flame()
{
}

template <class T>
eEntityType			Flame<T>::getType() const
{
  return (FLAME);
}

template <class T>
Flame<T>::~Flame()
{
}
