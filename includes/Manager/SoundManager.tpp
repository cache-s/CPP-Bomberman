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

  _bIntro.LoadFromFile("assets/sound/Intro.wav");
  _bTick.LoadFromFile("assets/sound/Tick.wav");
  _bPause.LoadFromFile("assets/sound/Pause.wav");
  _bBonus.LoadFromFile("assets/sound/Bonus.wav");
  _bBomb.LoadFromFile("assets/sound/Bomb.wav");
  _bExplosion.LoadFromFile("assets/sound/Explosion.wav");
  _bVictory.LoadFromFile("assets/sound/Victory.wav");
  _bDeath.LoadFromFile("assets/sound/Death.wav");
}

SoundManager::~SoundManager()
{
}

void	SoundManager::initSound()
{
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
  _soundQ.push(sound);
  _soundQ.back().Play();
}

void	SoundManager::playTick(bool loop)
{
  sf::Sound	sound;

  sound.SetBuffer(_bTick);
  sound.SetLoop(loop);
  _soundQ.push(sound);
  _soundQ.back().Play();
}

void	SoundManager::playMenu(bool loop)
{
  if (!_music.OpenFromFile("assets/sound/Music.wav"))
    return;
  _music.SetLoop(loop);
  _music.Play();
}

void	SoundManager::playGame(bool loop)
{
  if (!_music.OpenFromFile("assets/sound/Music.wav"))
    return;
  _music.SetLoop(loop);
  _music.Play();
}

void	SoundManager::playPause(bool loop)
{
  sf::Sound	sound;

  sound.SetBuffer(_bPause);
  sound.SetLoop(loop);
  _soundQ.push(sound);
  _soundQ.back().Play();
}

void	SoundManager::playBonus(bool loop)
{
  sf::Sound	sound;

  sound.SetBuffer(_bBonus);
  sound.SetLoop(loop);
  _soundQ.push(sound);
  _soundQ.back().Play();
}

void	SoundManager::playBomb(bool loop)
{
  sf::Sound	sound;

  sound.SetBuffer(_bBomb);
  sound.SetLoop(loop);
  _soundQ.push(sound);
  _soundQ.back().Play();
}

void	SoundManager::playExplosion(bool loop)
{
  sf::Sound	sound;
  sound.SetBuffer(_bExplosion);
  sound.SetLoop(loop);
  _soundQ.push(sound);
  _soundQ.back().Play();
}

void	SoundManager::playVictory(bool loop)
{
  sf::Sound	sound;

  sound.SetBuffer(_bVictory);
  sound.SetLoop(loop);
  _soundQ.push(sound);
  _soundQ.back().Play();
}

void	SoundManager::playDeath(bool loop)
{
  sf::Sound	sound;

  sound.SetBuffer(_bDeath);
  sound.SetLoop(loop);
  _soundQ.push(sound);
  _soundQ.back().Play();
}

void	SoundManager::clearQ()
{
  if (_soundQ.size() > 0 && _soundQ.front().GetStatus() == sf::Sound::Status::Stopped)
    _soundQ.pop();
}
