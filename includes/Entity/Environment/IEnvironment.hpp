#ifndef				IENVIRONMENT_HPP_
# define			IENVIRONMENT_HPP_

# include			"AEntity.hpp"

template <class T, class U, class V>
class				IEnvironment : public AEntity<T, U, V>
{
public:
  virtual eEntityType		getType() const = 0;
};

#endif				/* IENVIRONMENT_HPP_ */
