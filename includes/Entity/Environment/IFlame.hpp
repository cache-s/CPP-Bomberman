#ifndef				IFLAME_HPP_
# define			IFLAME_HPP_

#include			"IEnvironment.hpp"

template <class T, class U, class V>
class				IFlame : public IEnvironment<T, U, V>
{
public:
  virtual eEntityType   getType() const = 0;
};

#endif				/* IFLAME_HPP_ */
