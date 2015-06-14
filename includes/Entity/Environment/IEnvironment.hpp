#ifndef				IENVIRONMENT_HPP_
# define			IENVIRONMENT_HPP_

# include			"AEntity.hpp"

template <typename T>
class				IEnvironment : public AEntity<T>
{
public:
  virtual eEntityType		getType() const = 0;
  virtual IEntity<T>		*clone(double x, double y) = 0;
  virtual ~IEnvironment() {};
};

#endif				/* IENVIRONMENT_HPP_ */
