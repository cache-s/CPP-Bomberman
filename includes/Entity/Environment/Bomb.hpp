#ifndef				BOMB_HPP_
# define			BOMB_HPP_

#include			"IBomb.hpp"

template <class T>
class				Bomb : public IBomb<T>
{
public:
  Bomb();
  ~Bomb();
  eEntityType			getType() const;
private:
};

#endif				/* BOMB_HPP_ */
