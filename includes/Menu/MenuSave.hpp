#ifndef				MENUSAVE_HPP_
# define			MENUSAVE_HPP_

# include			<iostream>
# include			<vector>

# include			"IMenu.hpp"

class				MenuSave : public IMenu
{
public:
  MenuSave();
  ~MenuSave();

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

#endif				//MENUSAVE_HPP_
