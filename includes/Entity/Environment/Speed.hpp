#ifndef				SPEED_HPP_
# define			SPEED_HPP_

# include			"IBonus.hpp"

template <class T, class U, class V>
class				Speed : public IBonus<T, U, V>
{
public:
  Speed();
  ~Speed();
  eEntityType			getType() const;
private:
};

#endif				/* SPEED_HPP_ */
