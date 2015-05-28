#ifndef				IPLAYER_HPP_
# define			IPLAYER_HPP_

# include			"ICharacter.hpp"

template <class T>
class				IPlayer : public ICharacter<T>
{
public:
  virtual eEntityType		getType() const = 0;
  virtual IEntity<T>		*clone(int x, int y) = 0;
  virtual ~IPlayer() {};
};

#endif				//IPLAYER_HPP_
