#ifndef				FLAME_HPP_
# define			FLAME_HPP_

#include			"IFlame.hpp"

template <class T, class U, class V>
class				Flame : public IFlame<T, U, V>
{
public:
  Flame();
  ~Flame();
  eEntityType		getType() const;
private:
};

#endif				/* FLAME_HPP_ */