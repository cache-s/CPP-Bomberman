#ifndef				MENUEND_HPP_
# define			MENUEND_HPP_

# include			<iostream>
# include			<vector>

# include			"IMenu.hpp"

class				MenuEnd : public IMenu
{
public:
  MenuEnd();
  ~MenuEnd();

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

#endif				//MENUEND_HPP_
