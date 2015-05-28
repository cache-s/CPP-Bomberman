#ifndef		COLOR_HPP_
# define	COLOR_HPP_

# include	<iostream>
# include	<map>

class Color
{
public:
  enum	eColor
    {
      RESET,
      BLACK,
      RED,
      GREEN,
      YELLOW,
      BLUE,
      MAGENTA,
      CYAN,
      WHITE,
      BOLDBLACK,
      BOLDRED,
      BOLDGREEN,
      BOLDYELLOW,
      BOLDBLUE,
      BOLDMAGENTA,
      BOLDCYAN,
      BOLDWHITE
    };
  Color();
  std::string set(Color::eColor e);
private:
  std::map<eColor, std::string> _colors;
};

#endif /* COLOR */
