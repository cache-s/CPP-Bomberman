#ifndef				MENUSCORE_HPP_
# define			MENUSCORE_HPP_

# include			<iostream>
# include			<vector>

# include			"IMenu.hpp"

class				MenuScore : public IMenu
{
public:
  MenuScore();
  ~MenuScore();

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

#endif				//MENUSCORE_HPP_