#ifndef				IENVIRONMENT_HPP_
# define			IENVIRONMENT_HPP_

#include			"AEntity.hpp"

class				IEnvironment : public AEntity
{
public:
  virtual eEntityType		getType() const = 0;
};

#endif				/* IENVIRONMENT_HPP_ */
