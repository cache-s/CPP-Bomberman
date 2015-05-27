#ifndef				IBOMB_HPP_
# define			IBOMB_HPP_

#include			"IEnvironment.hpp"

template <class T>
class				IBomb : public IEnvironment<T>
{
public:
  virtual eEntityType		getType() const = 0;
  virtual IEntity<T>	*clone() = 0;
  virtual ~IBomb() {};
};

#endif				/* IBOMB_HPP_ */
