#ifndef				RADIUS_HPP_
# define			RADIUS_HPP_

# include			"IBonus.hpp"

template <class T>
class				Radius : public IBonus<T>
{
public:
  Radius();
  ~Radius();
  eEntityType			getType() const;
private:
};

#endif				/* RADIUS_HPP_ */
