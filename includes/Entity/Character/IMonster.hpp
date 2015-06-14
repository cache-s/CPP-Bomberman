#ifndef				IMONSTER_HPP_
# define			IMONSTER_HPP_

# include			"ICharacter.hpp"

template <typename T>
class				IMonster : public ICharacter<T>
{
public:
  virtual eEntityType		getType() const = 0;
  virtual IEntity<T>		*clone(double x, double y) = 0;
  virtual ~IMonster() {};
};

#endif				//IMONSTER_HPP_
