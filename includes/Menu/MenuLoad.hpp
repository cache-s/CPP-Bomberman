#ifndef				MENULOAD_HPP_
# define			MENULOAD_HPP_

# include			<iostream>
# include			<vector>

class				MenuLoad
{
public:
  MenuLoad();
  ~MenuLoad();

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

#endif				//MENULOAD_HPP_