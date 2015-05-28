#include "Color.hpp"

Color::Color()
{
  _colors[RESET] = "\033[0m";
  _colors[BLACK] = "\033[30m";
  _colors[RED] = "\033[31m"; 
  _colors[GREEN] = "\033[32m";
  _colors[YELLOW] = "\033[33m";
  _colors[BLUE] = "\033[34m";
  _colors[MAGENTA] = "\033[35m";
  _colors[CYAN] = "\033[36m";
  _colors[WHITE] = "\033[37m";
  _colors[BOLDBLACK] = "\033[1m\033[30m";
  _colors[BOLDRED] = "\033[1m\033[31m";
  _colors[BOLDGREEN] = "\033[1m\033[32m";
  _colors[BOLDYELLOW] = "\033[1m\033[33m";
  _colors[BOLDBLUE] = "\033[1m\033[34m";
  _colors[BOLDMAGENTA] = "\033[1m\033[35m";
  _colors[BOLDCYAN] = "\033[1m\033[36m";
  _colors[BOLDWHITE] = "\033[1m\033[37m";
}

std::string Color::set(Color::eColor e)
{
  std::map<eColor, std::string>::const_iterator it;
  it = _colors.find(e);
  if (it == _colors.end())
    return "";
  return it->second;
}
