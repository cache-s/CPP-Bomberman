#ifndef				IFLOOR_HPP_
# define			IFLOOR_HPP_

# include			"IEnvironment.hpp"

template <typename T>
class				IFloor : public IEnvironment<T>
{
public:
  virtual eEntityType		getType() const = 0;
  virtual IEntity<T>		*clone(double x, double y) = 0;
  virtual			~IFloor() {};
};


#endif				//IFLOOR_HPP_
