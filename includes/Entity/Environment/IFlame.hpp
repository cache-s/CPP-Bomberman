#ifndef				IFLAME_HPP_
# define			IFLAME_HPP_

#include			"IEnvironment.hpp"

template <typename T>
class				IFlame : public IEnvironment<T>
{
public:
  virtual eEntityType   getType() const = 0;
  virtual IEntity<T>	*clone(double x, double y) = 0;
  virtual bool		isDrop() const = 0;
  virtual void		setDrop(bool drop) = 0;
  virtual ~IFlame() {};
};

#endif				/* IFLAME_HPP_ */
