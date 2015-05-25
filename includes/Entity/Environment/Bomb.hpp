#ifndef				BOMB_HPP_
# define			BOMB_HPP_

#include			"IBomb.hpp"

template <class T, class U, class V>
class				Bomb : public IBomb<T, U, V>
{
public:
  Bomb();
  ~Bomb();
  eEntityType			getType() const;
private:
};

#endif				/* BOMB_HPP_ */
