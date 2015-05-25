#ifndef				IWALL_HPP_
# define			IWALL_HPP_

#include			"IEnvironment.hpp"

template <class T, class U, class V>
class				IWall : public  IEnvironment<T, U, V>
{
public:
  virtual eEntityType   getType() const = 0;
};

#endif				/* IWALL_HPP_ */
