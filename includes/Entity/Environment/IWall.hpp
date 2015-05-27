#ifndef				IWALL_HPP_
# define			IWALL_HPP_

#include			"IEnvironment.hpp"

template <class T>
class				IWall : public  IEnvironment<T>
{
public:
  virtual eEntityType   getType() const = 0;
  virtual IEntity<T>	*clone() = 0;
  virtual ~IWall() {};
};

#endif				/* IWALL_HPP_ */
