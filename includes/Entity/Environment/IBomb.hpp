#ifndef				IBOMB_HPP_
# define			IBOMB_HPP_

#include			"IEnvironment.hpp"

template <typename T>
class				IBomb : public IEnvironment<T>
{
public:
  virtual eEntityType		getType() const = 0;
  virtual IEntity<T>		*clone(double x, double y) = 0;
  virtual int                   getRadius() const = 0;
  virtual void                  setRadius(int nb) = 0;
  virtual ~IBomb() {};
};

#endif				/* IBOMB_HPP_ */
