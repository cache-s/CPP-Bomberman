#ifndef				IAI_HPP_
# define			IAI_HPP_

# include			"ICharacter.hpp"

class				IAI : public ICharacter
{
public:
  virtual eEntityType		getType() const = 0;
};

#endif				//IAI_HPP_
