#ifndef				IMONSTER_HPP_
# define			IMONSTER_HPP_

# include			"ICharacter.hpp"

template <class T>
class				IMonster : public ICharacter<T>
{
public:
  virtual eEntityType		getType() const = 0;
};

#endif				//IMONSTER_HPP_
