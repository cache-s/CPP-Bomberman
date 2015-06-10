#ifndef				MENUSTART_HPP_
# define			MENUSTART_HPP_

# include			<iostream>
# include			<vector>

class				MenuStart
{
public:
  MenuStart();
  ~MenuStart();

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

#endif				//MENUSTART_HPP_
