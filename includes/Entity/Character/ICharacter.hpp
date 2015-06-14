#ifndef				ICHARACTER_HPP_
# define			ICHARACTER_HPP_

# include			"AEntity.hpp"

template <class T>
class				ICharacter : public AEntity<T>
{
public:
  virtual eEntityType		getType() const = 0;
  virtual IEntity<T>		*clone(double x, double y) = 0;
  virtual ~ICharacter() {};
};

#endif				//ICHARACTER_HPP_
