#ifndef				UBRKWALL_HPP_
# define			UBRKWALL_HPP_

# include			"IWall.hpp"

template <class T, class U, class V>
class				UbrkWall : public IWall<T, U, V>
{
public:
  UbrkWall();
  ~UbrkWall();
  eEntityType			getType() const;
private:
};

#endif				/* UBRKWALL_HPP_ */
