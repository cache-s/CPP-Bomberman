#ifndef				IWALL_HPP_
# define			IWALL_HPP__

#include			"IEnvironment.hpp"

class				IWall : public  IEnvironment
{
public:
  virtual eEntityType   getType() const = 0;
};

#endif				/* IWALL_HPP_ */
