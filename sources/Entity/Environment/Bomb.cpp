//
// Bomb.cpp for  in /home/poupon_d/rendu/cpp_bomberman/sources/Entity/Environment
// 
// Made by delphine poupon
// Login   <poupon_d@epitech.net>
// 
// Started on  Fri May 22 15:22:25 2015 delphine poupon
// Last update Tue May 26 11:45:50 2015 Mathieu Bourmaud
//

#include			"Bomb.hpp"

template <class T>
Bomb<T>::Bomb()
{
}

template <class T>
eEntityType			Bomb<T>::getType() const
{
  return (BOMB);
}

template <class T>
Bomb<T>::~Bomb()
{
}
