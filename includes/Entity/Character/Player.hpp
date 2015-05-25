#ifndef				PLAYER_HPP_
# define			PLAYER_HPP_

# include			"IPlayer.hpp"

class				Player : public IPlayer
{
public:
  Player();
  ~Player();
  eEntityType			getType() const;
};

#endif				//PLAYER_HPP_
