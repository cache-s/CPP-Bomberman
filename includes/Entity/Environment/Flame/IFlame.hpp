#ifndef				IFLAME_HPP_
# define			IFLAME_HPP__

#include			"IEnvironment.hpp"

class				IFlame : public IEnvironment
{
public:
  virtual eEntityType   getType() const = 0;
};

#endif				/* IFLAME_HPP_ */
