#ifndef				IMONSTER_HPP_
# define			IMONSTER_HPP_

# include			"ICharacter.hpp"

class				IMonster : public ICharacter
{
public:
  virtual eEntityType		getType() const = 0;
};

#endif				//IMONSTER_HPP_
