#ifndef				IWALL_HPP_
# define			IWALL_HPP_

#include			"IEnvironment.hpp"

template <class T>
class				IWall : public  IEnvironment<T>
{
public:
  virtual eEntityType   getType() const = 0;
};

#endif				/* IWALL_HPP_ */
