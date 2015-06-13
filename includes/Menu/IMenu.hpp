#ifndef				IMENU_HPP_
# define			IMENU_HPP_

# include			<iostream>
# include			<vector>

class				IMenu
{
public:
  virtual void				setIndex(int index) = 0;
  virtual int				getIndex(void) const = 0;
  virtual int				getMaxIndex(void) const = 0;
  virtual std::vector<std::string>	getScene(void) const = 0;
};

#endif				//IMENU_HPP_
