//
// ISound.hh for bomber in /home/chazot_a/rendu/cpp_bomberman/sources/Audio
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Tue May 19 11:54:27 2015 Jordan Chazottes
// Last update Tue May 19 11:58:01 2015 Jordan Chazottes
//

#ifndef		ISOUND_HH_
# define	ISOUND_HH_

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

#endif		/* ISOUND_HH_ */
