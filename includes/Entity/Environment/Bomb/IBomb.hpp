#ifndef				IBOMB_HPP_
# define			IBOMB_HPP__

#include			"IEnvironment.hpp"

class				IBomb : public IEnvironment
{
public:
  virtual eEntityType		getType() const = 0;
};

#endif				/* IBOMB_HPP_ */
