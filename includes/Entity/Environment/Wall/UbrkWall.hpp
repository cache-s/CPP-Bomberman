#ifndef				UBRKWALL_HPP_
# define			UBRKWALL_HPP_

# include			"IWall.hpp"

class				UbrkWall : public IWall
{
public:
  UbrkWall();
  ~UbrkWall();
  eEntityType			getType() const;
private:
};

#endif				/* UBRKWALL_HPP_ */