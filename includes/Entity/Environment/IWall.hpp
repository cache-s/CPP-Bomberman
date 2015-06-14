//
// IWall.hpp for bomberman in /home/chazot_a/rendu/cpp_bomberman
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Sun Jun 14 21:33:02 2015 Jordan Chazottes
// Last update Sun Jun 14 21:33:06 2015 Jordan Chazottes
//

#ifndef				IWALL_HPP_
# define			IWALL_HPP_

#include			"IEnvironment.hpp"

template <typename T>
class				IWall : public  IEnvironment<T>
{
public:
  virtual eEntityType   getType() const = 0;
  virtual IEntity<T>	*clone(double x, double y) = 0;
  virtual ~IWall() {};
};

#endif				/* IWALL_HPP_ */
