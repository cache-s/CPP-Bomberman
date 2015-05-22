#ifndef				ICHARACTER_HPP_
# define			ICHARACTER_HPP_

# include			"IEntity.hpp"

class				ICharacter : public IEntity
{
public:
  virtual eEntityType		getType() const = 0;
};

#endif				//ICHARACTER_HPP_
