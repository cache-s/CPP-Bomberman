#ifndef		ISOUND_HPP_
# define	ISOUND_HPP_

class ISound
{
public:
  bombExplode() = 0;
  bombPose() = 0;
  moveSound() = 0;
  wallDestroyed() = 0;
  death() = 0;
  end() = 0;
  ambient() = 0;
  menuLeft() = 0;
  menuRight() = 0;
  menuUp() = 0;
  menuDown() = 0;
private:
}

#endif		/* ISOUND_HPP_ */
