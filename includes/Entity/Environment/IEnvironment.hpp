//
// IEnvironment.hpp for Bomberman in /home/chazot_a/rendu/cpp_bomberman
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Sun Jun 14 21:32:03 2015 Jordan Chazottes
// Last update Sun Jun 14 21:32:04 2015 Jordan Chazottes
//

#ifndef				IENVIRONMENT_HPP_
# define			IENVIRONMENT_HPP_

# include			"AEntity.hpp"

template <typename T>
class				IEnvironment : public AEntity<T>
{
public:
  virtual eEntityType		getType() const = 0;
  virtual IEntity<T>		*clone(double x, double y) = 0;
  virtual ~IEnvironment() {};
};

#endif				/* IENVIRONMENT_HPP_ */
