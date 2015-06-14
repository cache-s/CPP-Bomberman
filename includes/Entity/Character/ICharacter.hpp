//
// ICharacter.hpp for Bomberman in /home/chazot_a/rendu/cpp_bomberman
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Sun Jun 14 21:28:51 2015 Jordan Chazottes
// Last update Sun Jun 14 21:28:52 2015 Jordan Chazottes
//

#ifndef				ICHARACTER_HPP_
# define			ICHARACTER_HPP_

# include			"AEntity.hpp"

template <typename T>
class				ICharacter : public AEntity<T>
{
public:
  virtual eEntityType		getType() const = 0;
  virtual IEntity<T>		*clone(double x, double y) = 0;
  virtual ~ICharacter() {};
};

#endif				//ICHARACTER_HPP_
