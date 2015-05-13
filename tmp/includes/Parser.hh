//
// Parser.hh for  in /home/bourma_m/Projet/C++/cpp_plazza
// 
// Made by Mathieu Bourmaud
// Login   <bourma_m@epitech.net>
// 
// Started on  Mon Apr 13 12:09:47 2015 Mathieu Bourmaud
// Last update Thu Apr 23 17:10:17 2015 Mathieu Bourmaud
//

#ifndef		_PARSER_HH_
# define	_PARSER_HH_

#include	<stdexcept>
#include	<string>
#include	<algorithm>
#include	<sstream>
#include	<map>
#include	<vector>
#include	<iostream>
#include	"ParserExceptions.hh"

class		Parser
{
public:
  Parser(std::map<int, std::vector<std::string> > values);
  Parser();
  void		setValues(std::map<int, std::vector<std::string> > values);
  int		parseVector(std::vector<std::vector<std::string> > vector, size_t size, bool caseSensitive);
  void		checkVectors(const std::string &str, std::vector<std::string> value);
  void		checkVectorsNoCaseSensitive(const std::string &str, std::vector<std::string> value);
  bool		compareStrNoCaseSensitive(const std::string &c, const std::string &d);
  std::string	strToUpper(const std::string &str);
private:
  std::map<int, std::vector<std::string> > _values;
};

#endif
