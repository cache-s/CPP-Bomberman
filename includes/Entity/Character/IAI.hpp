#ifndef				IAI_HPP_
# define			IAI_HPP_

# include			"ICharacter.hpp"

template <typename T>
class				IAI : public ICharacter<T>
{
public:
  virtual eEntityType		getType() const = 0;
  virtual IEntity<T>		*clone(double x, double y) = 0;
  virtual ~IAI() {};
};

#endif				//IAI_HPP_
