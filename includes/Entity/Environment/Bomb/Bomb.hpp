#ifndef				BOMB_HPP_
# define			BOMB_HPP_

#include			"IBomb.hpp"

class				Bomb : public IBomb
{
public:
  Bomb();
  ~Bomb();
  eEntityType			getType() const;
private:
};

#endif				/* BOMB_HPP_ */
