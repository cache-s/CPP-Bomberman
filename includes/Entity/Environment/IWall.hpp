#ifndef				IWALL_HPP_
# define			IWALL_HPP_

#include			"IEnvironment.hpp"

template <typename T>
class				IWall : public  IEnvironment<T>
{
public:
  virtual eEntityType   getType() const = 0;
  virtual IEntity<T>	*clone(double x, double y) = 0;
  virtual ~IWall() {};
};

#endif				/* IWALL_HPP_ */
