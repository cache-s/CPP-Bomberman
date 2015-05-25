#ifndef				IBOMB_HPP_
# define			IBOMB_HPP_

#include			"IEnvironment.hpp"

template <class T, class U, class V>
class				IBomb : public IEnvironment<T, U, V>
{
public:
  virtual eEntityType		getType() const = 0;
};

#endif				/* IBOMB_HPP_ */
