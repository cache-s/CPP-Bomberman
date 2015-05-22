#ifndef					BRKWALL_HPP_
# define				BRKWALL_HPP_

# include				"IWall.hpp"

class					BrkWall : public IWall
{
public:
  BrkWall();
  ~BrkWall();
  eEntityType				getType() const;
private:
};

#endif					/* BRKWALL_HPP_ */
