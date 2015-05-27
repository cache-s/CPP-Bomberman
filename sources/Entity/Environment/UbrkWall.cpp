//
// UbrkWall.cpp for  in /home/poupon_d/rendu/cpp_bomberman/sources/Entity/Environment
// 
// Made by delphine poupon
// Login   <poupon_d@epitech.net>
// 
// Started on  Fri May 22 15:39:00 2015 delphine poupon
// Last update Wed May 27 11:06:09 2015 Mathieu Bourmaud
//

#include			"UbrkWall.hpp"

template <class T>
UbrkWall<T>::UbrkWall()
{
}

template <class T>
eEntityType			UbrkWall<T>::getType() const
{
  return (UBRKWALL);
}

template <class T>
UbrkWall<T>::~UbrkWall()
{
}
