#ifndef				MONSTER_HPP_
# define			MONSTER_HPP_

class				Monster : public IMonster
{
public:
  Monster();
  ~Monster();
  eEntityType   getType() const;
};

#endif				//MONSTER_HPP_
