#ifndef				IAI_HPP_
# define			IAI_HPP_

# include			"ICharacter.hpp"

template <class T>
class				IAI : public ICharacter<T>
{
public:
  virtual eEntityType		getType() const = 0;
  virtual IEntity<T>		*clone() = 0;
  virtual ~IAI() {};
};

#endif				//IAI_HPP_
