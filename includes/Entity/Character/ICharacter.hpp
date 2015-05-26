#ifndef				ICHARACTER_HPP_
# define			ICHARACTER_HPP_

# include			"IEntity.hpp"

template <class T>
class				ICharacter : public AEntity<T>
{
public:
  virtual eEntityType		getType() const = 0;
};

#endif				//ICHARACTER_HPP_
