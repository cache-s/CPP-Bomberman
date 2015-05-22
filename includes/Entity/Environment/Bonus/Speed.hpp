#ifndef				SPEED_HPP_
# define			SPEED_HPP_

# include			"IBonus.hpp"

class				Speed : public IBonus
{
public:
  Speed();
  ~Speed();
  eEntityType			getType() const;
private:
};

#endif				/* SPEED_HPP_ */
