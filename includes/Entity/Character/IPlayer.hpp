//
// IPlayer.hpp for Bomberman in /home/chazot_a/rendu/cpp_bomberman
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Sun Jun 14 21:29:05 2015 Jordan Chazottes
// Last update Sun Jun 14 21:29:06 2015 Jordan Chazottes
//

#ifndef				IPLAYER_HPP_
# define			IPLAYER_HPP_

# include			"ICharacter.hpp"

template <typename T>
class				IPlayer : public ICharacter<T>
{
public:
  virtual ~IPlayer() {};
  virtual eEntityType		getType() const = 0;
  virtual IEntity<T>		*clone(double x, double y) = 0;
  virtual int			getBombStock() const = 0;
  virtual void			setBombStock(int nb) = 0;
  virtual int			getRadius() const = 0;
  virtual void			setRadius(int nb) = 0;
};

#endif				//IPLAYER_HPP_
