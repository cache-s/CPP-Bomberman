#ifndef					BRKWALL_HPP_
# define				BRKWALL_HPP_

# include				"IWall.hpp"

template <class T, class U, class V>
class					BrkWall : public IWall<T, U, V>
{
public:
  BrkWall();
  ~BrkWall();
  eEntityType				getType() const;
private:
};

#endif					/* BRKWALL_HPP_ */
