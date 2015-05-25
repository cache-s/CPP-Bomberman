#ifndef				IBONUS_HPP_
# define			IBONUS_HPP_

#include			"IEnvironment.hpp"

template <class T, class U, class V>
class				IBonus : public IEnvironment<T, U, V>
{
public:
  virtual eEntityType		getType() const = 0;
};

#endif				/* IBONUS_HPP_ */
