//
// IBomb.hpp for Bomberman in /home/chazot_a/rendu/cpp_bomberman
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Sun Jun 14 21:31:55 2015 Jordan Chazottes
// Last update Sun Jun 14 21:31:56 2015 Jordan Chazottes
//

#ifndef				IBOMB_HPP_
# define			IBOMB_HPP_

#include			"IEnvironment.hpp"

template <typename T>
class				IBomb : public IEnvironment<T>
{
public:
  virtual eEntityType		getType() const = 0;
  virtual IEntity<T>		*clone(double x, double y) = 0;
  virtual int                   getRadius() const = 0;
  virtual void                  setRadius(int nb) = 0;
  virtual ~IBomb() {};
};

#endif				/* IBOMB_HPP_ */
