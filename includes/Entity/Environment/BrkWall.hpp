#ifndef					BRKWALL_HPP_
# define				BRKWALL_HPP_

# include				"IWall.hpp"

template <class T>
class					BrkWall : public IWall<T>
{
public:
  BrkWall();
  ~BrkWall();
  eEntityType				getType() const;
private:
};

#endif					/* BRKWALL_HPP_ */
