#ifndef				BOMBNUMBER_HPP_
# define			BOMBNUMBER_HPP_

# include			"IBonus.hpp"

class				BombNumber : public IBonus
{
public:
  BombNumber();
  ~BombNumber();
  eEntityType			getType() const;
private:
};

#endif				/* BOMBNUMBER_HPP__ */
