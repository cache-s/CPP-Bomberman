//
// IMonster.hpp for bomberman in /home/chazot_a/rendu/cpp_bomberman
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Sun Jun 14 21:28:59 2015 Jordan Chazottes
// Last update Sun Jun 14 21:29:00 2015 Jordan Chazottes
//

#ifndef				IMONSTER_HPP_
# define			IMONSTER_HPP_

# include			"ICharacter.hpp"

template <typename T>
class				IMonster : public ICharacter<T>
{
public:
  virtual eEntityType		getType() const = 0;
  virtual IEntity<T>		*clone(double x, double y) = 0;
  virtual ~IMonster() {};
};

#endif				//IMONSTER_HPP_
