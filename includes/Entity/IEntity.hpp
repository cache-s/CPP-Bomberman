#ifndef			IENTITY_HPP_
# define		IENTITY_HPP_

#include		"IObs.hpp"

enum			eEntityType
  {
    BOMB,
    MONSTER,
    AI,
    PLAYER,
  };

class			IEntity : public IObs
{
public:
  virtual int		getPosX() const = 0;
  virtual int		getPosY() const = 0;
  virtual eEntityType	getType() const = 0;
private:
};

#endif			/* IENTITY_HPP_ */
