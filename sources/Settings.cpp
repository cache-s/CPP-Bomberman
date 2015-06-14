#include			"Settings.hpp"

Settings::Settings()
{
  _playerNumber = 1;
  _aiNumber = 1;
  _mapSize = 50;
  _soundVolume = 5;
  _name = "AAA";
  _score = 0;
}

Settings::~Settings()
{

}

//GETTERS
int			Settings::getScore() const
{
  return (_score);
}

std::string		Settings::getName() const
{
  return (_name);
}

int			Settings::getMapSize() const
{
  return (_mapSize);
}

int			Settings::getPlayerNumber() const
{
  return (_playerNumber);
}

int			Settings::getAINumber() const
{
  return (_aiNumber);
}

int			Settings::getSoundVolume() const
{
  return (_soundVolume);
}

//SETTERS
void			Settings::setScore(int score)
{
  _score = score;
}

void			Settings::setName(const std::string & name)
{
  _name = name;
}

void			Settings::setMapSize(int size)
{
  _mapSize = size;
}

void			Settings::setPlayerNumber(int number)
{
  _playerNumber = number;
}

void			Settings::setAINumber(int number)
{
  _aiNumber = number;
}

void			Settings::setSoundVolume(int number)
{
  _soundVolume = number;
}
