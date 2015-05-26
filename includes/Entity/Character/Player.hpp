#ifndef				PLAYER_HPP_
# define			PLAYER_HPP_

# include			"IPlayer.hpp"

template <class T>
class				Player : public IPlayer<T>
{
public:
  Player();
  ~Player();
  eEntityType			getType() const;
};

#endif				//PLAYER_HPP_
