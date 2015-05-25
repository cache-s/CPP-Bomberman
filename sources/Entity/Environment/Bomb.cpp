//
// Bomb.cpp for  in /home/poupon_d/rendu/cpp_bomberman/sources/Entity/Environment
// 
// Made by delphine poupon
// Login   <poupon_d@epitech.net>
// 
// Started on  Fri May 22 15:22:25 2015 delphine poupon
// Last update Mon May 25 17:58:00 2015 Mathieu Bourmaud
//

#include			"Bomb.hpp"

template <class T, class U, class V>
Bomb<T, U, V>::Bomb()
{
}

template <class T, class U, class V>
eEntityType			Bomb<T, U, V>::getType() const
{
  return (BOMB);
}

template <class T, class U, class V>
Bomb<T, U, V>::~Bomb()
{
}
