#ifndef				IFLAME_HPP_
# define			IFLAME_HPP_

#include			"IEnvironment.hpp"

template <class T>
class				IFlame : public IEnvironment<T>
{
public:
  virtual eEntityType   getType() const = 0;
};

#endif				/* IFLAME_HPP_ */
