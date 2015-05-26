#ifndef				IPLAYER_HPP_
# define			IPLAYER_HPP_

# include			"ICharacter.hpp"

template <class T>
class				IPlayer : public ICharacter<T>
{
public:
  virtual eEntityType		getType() const = 0;
};

#endif				//IPLAYER_HPP_
