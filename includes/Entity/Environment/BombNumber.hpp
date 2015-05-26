#ifndef				BOMBNUMBER_HPP_
# define			BOMBNUMBER_HPP_

# include			"IBonus.hpp"

template <class T>
class				BombNumber : public IBonus<T>
{
public:
  BombNumber();
  ~BombNumber();
  eEntityType			getType() const;
private:
};

#endif				/* BOMBNUMBER_HPP__ */
