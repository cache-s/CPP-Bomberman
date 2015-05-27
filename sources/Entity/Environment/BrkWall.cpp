//
// BrkWall.cpp for  in /home/poupon_d/rendu/cpp_bomberman/sources/Entity/Environment
// 
// Made by delphine poupon
// Login   <poupon_d@epitech.net>
// 
// Started on  Fri May 22 15:34:09 2015 delphine poupon
// Last update Wed May 27 10:43:45 2015 Mathieu Bourmaud
//

#include			"BrkWall.hpp"

template <class T>
BrkWall<T>::BrkWall()
{
}

template <class T>
eEntityType			BrkWall<T>::getType() const
{
  return (BRKWALL);
}

template <class T>
BrkWall<T>::~BrkWall()
{
}
