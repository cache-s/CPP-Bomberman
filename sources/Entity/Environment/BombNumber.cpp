//
// BombNumber.cpp for  in /home/poupon_d/rendu/cpp_bomberman/sources/Entity/Environment
// 
// Made by delphine poupon
// Login   <poupon_d@epitech.net>
// 
// Started on  Fri May 22 15:25:38 2015 delphine poupon
// Last update Wed May 27 10:43:06 2015 Mathieu Bourmaud
//

#include			"BombNumber.hpp"

template <class T>
BombNumber<T>::BombNumber()
{
}

template <class T>
eEntityType			BombNumber<T>::getType() const
{
  return (BOMBNUMBER);
}

template <class T>
BombNumber<T>::~BombNumber()
{
}
