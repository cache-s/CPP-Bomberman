//
// SoundManager.tpp for bomberman in /home/chazot_a/rendu/cpp_bomberman/includes/Manager
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Sun Jun 14 21:23:50 2015 Jordan Chazottes
// Last update Sun Jun 14 22:56:20 2015 Jordan Chazottes
//

SoundManager::SoundManager()
{
  _soundFct[S_INTRO] = &SoundManager::playIntro;
  _soundFct[S_TICK] = &SoundManager::playTick;
  _soundFct[S_MENU] = &SoundManager::playMenu;
  _soundFct[S_GAME] = &SoundManager::playGame;
  _soundFct[S_PAUSE] = &SoundManager::playPause;
  _soundFct[S_BONUS] = &SoundManager::playBonus;
  _soundFct[S_BOMB] = &SoundManager::playBomb;
  _soundFct[S_EXPLOSION] = &SoundManager::playExplosion;
  _soundFct[S_VICTORY] = &SoundManager::playVictory;
  _soundFct[S_DEATH] = &SoundManager::playDeath;
}

SoundManager::~SoundManager()
{
}

void	SoundManager::initSound()
{
  _volume = 0;
  try
    {
      if (!_bIntro.LoadFromFile("assets/sound/Intro.wav"))
	throw std::runtime_error("Error while loading Intro.wav");
      if (!_bTick.LoadFromFile("assets/sound/Tick.wav"))
	throw std::runtime_error("Error while loading Tick.wav");
      if (!_bPause.LoadFromFile("assets/sound/Pause.wav"))
	throw std::runtime_error("Error while loading Pause.wav");
      if (!_bBonus.LoadFromFile("assets/sound/Bonus.wav"))
	throw std::runtime_error("Error while loading Bonus.wav");
      if (!_bBomb.LoadFromFile("assets/sound/Bomb.wav"))
	throw std::runtime_error("Error while loading Bomb.wav");
      if (!_bExplosion.LoadFromFile("assets/sound/Explosion.wav"))
	throw std::runtime_error("Error while loading Explosion.wav");
      if (!_bVictory.LoadFromFile("assets/sound/Victory.wav"))
	throw std::runtime_error("Error while loading Victory.wav");
      if (!_bDeath.LoadFromFile("assets/sound/Death.wav"))
	throw std::runtime_error("Error while loading Death.wav");
    }
  catch (const std::runtime_error& e)
    {
      std::cerr << "Exception : " << e.what() << std::endl;
    }
}

void	SoundManager::playSound(eSoundType sound, bool loop)
{
  clearQ();
  (this->*_soundFct[sound])(loop);
}

void	SoundManager::playIntro(bool loop)
{
  sf::Sound	sound;

  sound.SetBuffer(_bIntro);
  sound.SetLoop(loop);
  sound.SetVolume(_volume);
  _soundQ.push(sound);
  _soundQ.back().Play();
}

void	SoundManager::playTick(bool loop)
{
  sf::Sound	sound;

  sound.SetBuffer(_bTick);
  sound.SetLoop(loop);
  sound.SetVolume(_volume);
  _soundQ.push(sound);
  _soundQ.back().Play();
}

void	SoundManager::playMenu(bool loop)
{
  try
    {
      if (!_music.OpenFromFile("assets/sound/Music.wav"))
	throw std::runtime_error("Error while opening Music.wav");
      _music.SetLoop(loop);
      _music.SetVolume(_volume);
      _music.Play();    
    }
  catch (const std::runtime_error& e)
    {
      std::cout << "Exception : " << e.what() << std::endl;
    }
}

void	SoundManager::playGame(bool loop)
{
  try
    {
      if (!_music.OpenFromFile("assets/sound/Game.wav"))
	throw std::runtime_error("Error while opening Game.wav");
      _music.SetLoop(loop);
      _music.SetVolume(_volume);
      _music.Play();
    }
  catch (const std::runtime_error& e)
    {
      std::cout << "Exception : " << e.what() << std::endl;
    }
}

void	SoundManager::playPause(bool loop)
{
  sf::Sound	sound;

  sound.SetBuffer(_bPause);
  sound.SetLoop(loop);
  sound.SetVolume(_volume);
  _soundQ.push(sound);
  _soundQ.back().Play();
}

void	SoundManager::playBonus(bool loop)
{
  sf::Sound	sound;

  sound.SetBuffer(_bBonus);
  sound.SetLoop(loop);
  sound.SetVolume(_volume);
  _soundQ.push(sound);
  _soundQ.back().Play();
}

void	SoundManager::playBomb(bool loop)
{
  sf::Sound	sound;

  sound.SetBuffer(_bBomb);
  sound.SetLoop(loop);
  sound.SetVolume(_volume);
  _soundQ.push(sound);
  _soundQ.back().Play();
}

void	SoundManager::playExplosion(bool loop)
{
  sf::Sound	sound;

  sound.SetBuffer(_bExplosion);
  sound.SetLoop(loop);
  sound.SetVolume(_volume);
  _soundQ.push(sound);
  _soundQ.back().Play();
}

void	SoundManager::playVictory(bool loop)
{
  sf::Sound	sound;

  sound.SetBuffer(_bVictory);
  sound.SetLoop(loop);
  sound.SetVolume(_volume);
  _soundQ.push(sound);
  _soundQ.back().Play();
}

void	SoundManager::playDeath(bool loop)
{
  sf::Sound	sound;

  sound.SetBuffer(_bDeath);
  sound.SetLoop(loop);
  sound.SetVolume(_volume);
  _soundQ.push(sound);
  _soundQ.back().Play();
}

void	SoundManager::clearQ()
{
  if (_soundQ.size() > 0 && _soundQ.front().GetStatus() == sf::Sound::Status::Stopped)
    _soundQ.pop();
}

void	SoundManager::mute()
{
  _volume = 0;
  updateQ();
  _music.SetVolume(0);
}

void	SoundManager::unmute()
{
  _volume = 100;
  updateQ();
  _music.SetVolume(100);
}

void	SoundManager::updateQ()
{
  _soundQ.back().SetVolume(_volume);
  _soundQ.front().SetVolume(_volume);
}

int	SoundManager::getVolume() const
{
  return (_volume);
}
