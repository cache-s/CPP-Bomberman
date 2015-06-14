//
// IAI.hpp for Bomberman in /home/chazot_a/rendu/cpp_bomberman
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Sun Jun 14 21:28:43 2015 Jordan Chazottes
// Last update Sun Jun 14 21:28:44 2015 Jordan Chazottes
//

#ifndef				IAI_HPP_
# define			IAI_HPP_

# include			"ICharacter.hpp"

template <typename T>
class				IAI : public ICharacter<T>
{
public:
  virtual eEntityType		getType() const = 0;
  virtual IEntity<T>		*clone(double x, double y) = 0;
  virtual ~IAI() {};
};

#endif				//IAI_HPP_
