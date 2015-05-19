//
// IEntity.hh for  in /home/poupon_d/rendu/cpp_bomberman/sources/Entity
// 
// Made by delphine poupon
// Login   <poupon_d@epitech.net>
// 
// Started on  Tue May 19 14:19:59 2015 delphine poupon
// Last update Tue May 19 14:19:59 2015 delphine poupon
//

#ifndef			IENTITY_HH_
# define		IENTITY_HH_

#include		"IObs.hh"

class			IEntity : public IObs
{
public:
  virtual int		getPosX() const = 0;
  virtual int		getPosY() const = 0;
private:
};

#endif			/* IENTITY_HH_ */
