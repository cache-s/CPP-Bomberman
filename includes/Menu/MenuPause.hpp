#ifndef				MENUPAUSE_HPP_
# define			MENUPAUSE_HPP_

# include			<iostream>
# include			<vector>

# include			"IMenu.hpp"

class				MenuPause : public IMenu
{
public:
  MenuPause();
  ~MenuPause();

  //SETTERS
  void				setIndex(int index);

  //GETTERS
  int				getIndex(void) const;
  int				getMaxIndex(void) const;
  std::vector<std::string>	getScene() const;

private:
  std::vector<std::string>	_scene;
  int				_index;
};

#endif				//MENUPAUSE_HPP_
