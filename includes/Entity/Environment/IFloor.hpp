//
// IFloor.hpp for bomberman in /home/chazot_a/rendu/cpp_bomberman
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Sun Jun 14 21:32:54 2015 Jordan Chazottes
// Last update Sun Jun 14 21:32:55 2015 Jordan Chazottes
//

#ifndef				IFLOOR_HPP_
# define			IFLOOR_HPP_

# include			"IEnvironment.hpp"

template <typename T>
class				IFloor : public IEnvironment<T>
{
public:
  virtual eEntityType		getType() const = 0;
  virtual IEntity<T>		*clone(double x, double y) = 0;
  virtual			~IFloor() {};
};


#endif				//IFLOOR_HPP_
