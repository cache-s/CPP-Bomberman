#ifndef				IBONUS_HPP_
# define			IBONUS_HPP_

#include			"IEnvironment.hpp"

template <class T>
class				IBonus : public IEnvironment<T>
{
public:
  virtual eEntityType		getType() const = 0;
  virtual IEntity<T>		*clone(double x, double y) = 0;
  virtual ~IBonus() {};
};

#endif				/* IBONUS_HPP_ */
