#ifndef				IBONUS_HPP_
# define			IBONUS_HPP__

#include			"IEnvironment.hpp"

class				IBonus : public IEnvironment
{
public:
  virtual eEntityType		getType() const = 0;
};

#endif				/* IBONUS_HPP_ */
