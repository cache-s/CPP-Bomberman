#ifndef				IENVIRONMENT_HPP_
# define			IENVIRONMENT_HPP_

# include			"AEntity.hpp"

template <class T>
class				IEnvironment : public AEntity<T>
{
public:
  virtual eEntityType		getType() const = 0;
};

#endif				/* IENVIRONMENT_HPP_ */
