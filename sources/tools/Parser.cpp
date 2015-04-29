//
// Parser.cpp for  in /home/bourma_m/Projet/C++/cpp_plazza
// 
// Made by Mathieu Bourmaud
// Login   <bourma_m@epitech.net>
// 
// Started on  Mon Apr 13 12:11:48 2015 Mathieu Bourmaud
// Last update Thu Apr 23 17:11:44 2015 Mathieu Bourmaud
//

#include		"Parser.hh"

Parser::Parser(std::map<int, std::vector<std::string> > values)
{
  _values = values;
}

Parser::Parser()
{
}

void			Parser::setValues(std::map<int, std::vector<std::string> > values)
{
  _values = values;
}

int			Parser::parseVector(std::vector<std::vector<std::string> > vector, size_t size, bool caseSensitive)
{
  size_t		i = 0;
  size_t		j = 0;
  std::string		str;
  
  try
    {
      while (i < vector.size())
	{
	  j = 0;
	  while (j < size)
	    {
	      if (caseSensitive)
		checkVectors(vector[i][j], _values[j]);
	      else
		checkVectorsNoCaseSensitive(vector[i][j], _values[j]);
	      j++;
	    }
	  i++;
	}  
    }
  catch (const ParserExceptions &e)
    { 
      throw;
      return (-1);
    }
  return (0);
}

void			Parser::checkVectorsNoCaseSensitive(const std::string &str, std::vector<std::string> values)
{
  size_t		i = 0;
  int			occ = 0;
  std::string		res;

  while (i < values.size())
    {
      if (compareStrNoCaseSensitive(str, values[i]) == true)
	occ++;
      i++;
    }
  res = "Parser error : " + str + " is not part of ";
  i = 0;
  while (i < values.size())
    {
      res += values[i];
      res += "/";
      i++;
    }
  if (occ == 0)
    throw ParserExceptions(res); 
}

void			Parser::checkVectors(const std::string &str, std::vector<std::string> values)
{
  size_t		i = 0;
  int			occ = 0;
  std::string		res;

  while (i < values.size())
    {
      if (str == values[i])
	occ++;
      i++;
    }
  res = "Parse error : " + str + " is not part of ";
  i = 0;
  while (i < values.size())
    {
      res += values[i];
      res += "/";
      i++;
    }
  if (occ == 0)
    throw ParserExceptions(res); 
}

bool			Parser::compareStrNoCaseSensitive(const std::string &c, const std::string &d)
{
  size_t		i = 0;
  size_t		occ = 0;
  
  while (c[i])
    {
      if (toupper(c[i]) == toupper(d[i]))
	occ++;
      i++;
    }
  if (occ != c.length())
    return (false);
  return (true);
}

std::string		Parser::strToUpper(const std::string &str)
{  
  std::string		toUp;

  toUp = str;
  std::transform(toUp.begin(), toUp.end(), toUp.begin(), ::toupper);
  return (toUp);
}
