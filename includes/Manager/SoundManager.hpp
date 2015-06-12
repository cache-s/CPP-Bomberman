#ifndef			SOUNDMANAGER_HPP_
# define		SOUNDMANAGER_HPP_

# include		<iostream>
# include		<map>
# include		<SDL/SDL.h>
# include		<SFML/Audio.hpp>
# include		<SFML/Audio/SoundBuffer.hpp>

enum			eSoundType
  {
    S_INTRO,
    S_TICK,
    S_MENU,
    S_GAME,
    S_PAUSE,
    S_BONUS,
    S_BOMB,
    S_EXPLOSION,
    S_VICTORY,
    S_DEATH,
  };

class			SoundManager
{
public:
  SoundManager();
  ~SoundManager();
  void			initSound();
  void			playSound(eSoundType sound, bool loop = false);
private:
  void			playIntro(bool loop);
  void			playTick(bool loop);
  void			playMenu(bool loop);
  void			playGame(bool loop);
  void			playPause(bool loop);
  void			playBonus(bool loop);
  void			playBomb(bool loop);
  void			playExplosion(bool loop);
  void			playVictory(bool loop);
  void			playDeath(bool loop);
  void			clearQ();

  typedef void	(SoundManager::*playFct)(bool loop);
  std::map<eSoundType, playFct> _soundFct;
  std::queue<sf::Sound>	_soundQ;
   sf::Music		_music;

  sf::SoundBuffer	_bIntro;
  sf::SoundBuffer	_bTick;
  sf::SoundBuffer	_bPause;
  sf::SoundBuffer	_bBonus;
  sf::SoundBuffer	_bBomb;
  sf::SoundBuffer	_bExplosion;
  sf::SoundBuffer	_bVictory;
  sf::SoundBuffer	_bDeath;
};

#include		"SoundManager.tpp"

#endif			//SOUNDMANAGER_HPP_