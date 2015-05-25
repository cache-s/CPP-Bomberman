#ifndef				RADIUS_HPP_
# define			RADIUS_HPP_

# include			"IBonus.hpp"

template <class T, class U, class V>
class				Radius : public IBonus<T, U, V>
{
public:
  Radius();
  ~Radius();
  eEntityType			getType() const;
private:
};

#endif				/* RADIUS_HPP_ */
