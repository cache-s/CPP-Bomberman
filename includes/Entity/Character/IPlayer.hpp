#ifndef				IPLAYER_HPP_
# define			IPLAYER_HPP_

# include			"ICharacter.hpp"

class				IPlayer : public ICharacter
{
public:
  virtual eEntityType		getType() const = 0;
};

#endif				//IPLAYER_HPP_
