#ifndef				RADIUS_HPP_
# define			RADIUS_HPP_

# include			"IBonus.hpp"

class				Radius : public IBonus
{
public:
  Radius();
  ~Radius();
  eEntityType			getType() const;
private:
};

#endif				/* RADIUS_HPP_ */
