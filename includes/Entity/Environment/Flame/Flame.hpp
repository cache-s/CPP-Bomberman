#ifndef				FLAME_HPP_
# define			FLAME_HPP_

#include			"IFlame.hpp"

class				Flame : public IFlame
{
public:
  Flame();
  ~Flame();
  eEntityType		getType() const;
private:
};

#endif				/* FLAME_HPP_ */
