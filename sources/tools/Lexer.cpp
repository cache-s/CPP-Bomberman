//
// Lexer.cpp for  in /home/bourma_m/Projet/C++/cpp_plazza
// 
// Made by Mathieu Bourmaud
// Login   <bourma_m@epitech.net>
// 
// Started on  Mon Apr 13 15:17:21 2015 Mathieu Bourmaud
// Last update Sat Apr 25 17:35:56 2015 Mathieu Bourmaud
//

#include		"Lexer.hh"

Lexer::Lexer()
{
}

Lexer::Lexer(std::map<int, std::string> grammar)
{
  _grammar = grammar;
  _tokens.clear();
}

void				Lexer::clearTokens()
{
  _tokens.clear();
}

void				Lexer::setGrammar(std::map<int, std::string> grammar)
{
  _grammar = grammar;
  _tokens.clear();
}

std::map<int, std::string>	Lexer::getGrammar() const
{
  return (_grammar);
}

void				Lexer::checkGrammar()
{
  size_t			i = 0;
  size_t			j = 0;
  std::string			res;

  while (i < _tokens.size())
    {
      j = 0;
      while (j < _tokens[i].size())
	{
	  if (pregMatch(_tokens[i][j], _grammar[j]) == -1)
	    {
	      res = "Lexer error : " + _tokens[i][j] + " is not part of " + _grammar[j];
	      throw LexerExceptions(res);
	    } 
	  j++;
	}
      i++;
    }  
}

void				Lexer::checkGrammar(std::vector <std::vector<std::string> > tokens)
{
  size_t			i = 0;
  size_t			j = 0;
  std::string			res;

  while (i < tokens.size())
    {
      j = 0;
      while (j < tokens[i].size())
	{
	  if (pregMatch(tokens[i][j], _grammar[j]) == -1)
	    {
	      res = "Lexer error : " + tokens[i][j] + " is not part of " + _grammar[j];
	      throw LexerExceptions(res);
	    } 
	  j++;
	}
      i++;
    }  
}

void				Lexer::splitToVectors(const std::string &line, const char delim)
{
  std::istringstream				str;
  std::string					s;
  size_t					j;
  std::vector<std::string>			vec;

  j = 0;
  if (line.empty())
    return;
  str.str(line);
  while (std::getline(str, s, delim))
    {
      if (s != "\0")
	{
	  vec.push_back(s);
	  j++;
	  if (j >= _grammar.size())
	    {
	      _tokens.push_back(vec);
	      vec.clear();
	    }
	}
    }
  if (j < _grammar.size())
    throw LexerExceptions("Lexer error : your order must be like this -> [Pizza type] [Size] [Number]");
}

void				Lexer::displayVectors() const
{
  size_t			i = 0;
  size_t			j = 0;

  std::cout << "DISPLAYING VECTORS" << std::endl;
  std::cout << "------------------" << std::endl;
  while (i < _tokens.size())
    {
      j = 0;
      while (j < _tokens[i].size())
	{
	  std::cout << "tokens[" << i << "][" << j << "]=" << _tokens[i][j] << std::endl;
	  j++;
	}
      i++;
    }
  std::cout << "------------------" << std::endl;
}

void				Lexer::displayVectors(std::vector<std::vector<std::string > > tokens) const
{
  size_t			i = 0;
  size_t			j = 0;

  std::cout << "DISPLAYING VECTORS" << std::endl;
  std::cout << "------------------" << std::endl;
  while (i < tokens.size())
    {
      j = 0;
      while (j < tokens[i].size())
	{
	  std::cout << "tokens[" << i << "][" << j << "]=" << tokens[i][j] << std::endl;
	  j++;
	}
      i++;
    }
  std::cout << "------------------" << std::endl;
}

std::vector<std::vector<std::string> > Lexer::getTokens() const
{
  return (_tokens);
}

int				Lexer::pregMatch(const std::string &str, const std::string &good) const
{
  int		i;
  int		j;
  size_t	occ;

  i = 0;
  occ = 0;
  while (str[i])
    {
      j = 0;
      while (good[j])
	{
	  if (str[i] == good[j])
	    occ++;
	  j++;
	}
      i++;
    }
  if (occ != str.length())
    return (-1);
  return (1);
}

int				Lexer::countChar(const std::string &str, const char c) const
{
  int			occ;
  int			i;

  occ = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] == c)
	occ++;
      i++;
    }
  return (occ);
}

std::string			Lexer::removeSpaces(std::string &str) const
{
  str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
  return (str);
}

bool				Lexer::checkPositionOfStringInStr(const std::string &str, const std::string &needle, const size_t pos) const
{
  size_t			found;

  found = str.find(needle);
  if (found != pos)
    return (false);
  return (true);
}
