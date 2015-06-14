//
// IBonus.hpp for Bomberman in /home/chazot_a/rendu/cpp_bomberman
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Sun Jun 14 21:31:59 2015 Jordan Chazottes
// Last update Sun Jun 14 21:31:59 2015 Jordan Chazottes
//

#ifndef				IBONUS_HPP_
# define			IBONUS_HPP_

#include			"IEnvironment.hpp"

template <typename T>
class				IBonus : public IEnvironment<T>
{
public:
  virtual eEntityType		getType() const = 0;
  virtual IEntity<T>		*clone(double x, double y) = 0;
  virtual ~IBonus() {};
};

#endif				/* IBONUS_HPP_ */
