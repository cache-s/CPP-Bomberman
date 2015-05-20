#ifndef				AMENU_HPP_
# define			AMENU_HPP_

# include			"IMenu.hpp"

class				AMenu : public IMenu
{
public:
  virtual void			display() = 0;
};

#endif				//AMENU_HPP_
