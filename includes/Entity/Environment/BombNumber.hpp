#ifndef				BOMBNUMBER_HPP_
# define			BOMBNUMBER_HPP_

# include			"IBonus.hpp"

template <class T, class U, class V>
class				BombNumber : public IBonus<T, U, V>
{
public:
  BombNumber();
  ~BombNumber();
  eEntityType			getType() const;
private:
};

#endif				/* BOMBNUMBER_HPP__ */
