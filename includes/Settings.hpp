//
// Settings.hpp for Bomberman in /home/chazot_a/rendu/cpp_bomberman/includes
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Sun Jun 14 21:24:06 2015 Jordan Chazottes
// Last update Sun Jun 14 21:24:07 2015 Jordan Chazottes
//

#ifndef			SETTINGS_HPP_
# define		SETTINGS_HPP_

# include		<iostream>

class			Settings
{
public:
  Settings();
  ~Settings();

  //GETTERS

  int			getMapSize() const;
  int			getScore() const;
  std::string		getName() const;
  int			getPlayerNumber() const;
  int			getAINumber() const;
  int			getSoundVolume() const;

  //SETTERS

  void			setScore(int score);
  void			setName(const std::string & name);
  void			setMapSize(int size);
  void			setPlayerNumber(int number);
  void			setAINumber(int number);
  void			setSoundVolume(int number);

private:

  int			_score;
  int			_playerNumber;
  int			_aiNumber;
  int			_mapSize;
  int			_soundVolume;
  std::string		_name;
};

#endif			//SETTINGS_HPP_
