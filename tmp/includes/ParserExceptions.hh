//
// ParserExceptions.hh for  in /home/bourma_m/Projet/C++/cpp_plazza
// 
// Made by Mathieu Bourmaud
// Login   <bourma_m@epitech.net>
// 
// Started on  Tue Apr 21 10:36:26 2015 Mathieu Bourmaud
// Last update Sun Apr 26 04:30:23 2015 Mathieu Bourmaud
//

#ifndef			_PARSER_EXCEPTIONS_HH_
# define		_PARSER_EXCEPTIONS_HH_

#include		<iostream>
#include		<stdexcept>

#define			ERR	"\x1b[31m"
#define			END	"\x1b[0m"

class			ParserExceptions : public std::domain_error
{
public:
  explicit		ParserExceptions(const std::string &arg);
private:
  const std::string	&_msg;
};

#endif
