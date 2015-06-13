#ifndef			SETTINGS_HPP_
# define		SETTINGS_HPP_

class			Settings
{
public:
  Settings();
  ~Settings();

  //GETTERS

  int			getMapSize() const;
  int			getPlayerNumber() const;
  int			getAINumber() const;
  int			getSoundVolume() const;

  //SETTERS

  void			setMapSize(int size);
  void			setPlayerNumber(int number);
  void			setAINumber(int number);
  void			setSoundVolume(int number);

private:

  int			_playerNumber;
  int			_aiNumber;
  int			_mapSize;
  int			_soundVolume;
};

#endif			//SETTINGS_HPP_
