#ifndef				MONSTER_HPP_
# define			MONSTER_HPP_

# include			"IMonster.hpp"

template <class T>
class				Monster : public IMonster<T>
{
public:
  Monster();
  ~Monster();
  eEntityType   getType() const;
};

#endif				//MONSTER_HPP_
