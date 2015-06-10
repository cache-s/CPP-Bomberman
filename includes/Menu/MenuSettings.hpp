#ifndef				MENUSETTINGS_HPP_
# define			MENUSETTINGS_HPP_

# include			<iostream>
# include			<vector>

class				MenuSettings
{
public:
  MenuSettings();
  ~MenuSettings();

  //SETTERS
  void				setIndex(int index);

  //GETTERS
  int				getIndex(void) const;
  int				getMaxIndex(void) const;
  std::string			getCurrentScene(void) const;
  std::vector<std::string>	getScene() const;

private:
  std::vector<std::string>	_scene;
  int				_index;
};

#endif				//MENUSETTINGS_HPP_
