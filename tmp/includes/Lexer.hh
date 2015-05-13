//
// Lexer.hh for  in /home/bourma_m/Projet/C++/cpp_plazza
// 
// Made by Mathieu Bourmaud
// Login   <bourma_m@epitech.net>
// 
// Started on  Mon Apr 13 14:59:18 2015 Mathieu Bourmaud
// Last update Sat Apr 25 17:35:45 2015 Mathieu Bourmaud
//

#ifndef			_LEXER_HH_
# define		_LEXER_HH_


#include		<stdexcept>
#include		<vector>
#include		<string>
#include		<cctype>
#include		<map>
#include		<algorithm>
#include		<iostream>
#include		<sstream>
#include		"Parser.hh"
#include		"LexerExceptions.hh"

#define			DELIM	';'
#define			SPACE	' '
#define			ALPHA	"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define			NUM	"0123456789"

class			Lexer
{
public:
  Lexer();
  Lexer(std::map<int, std::string> grammar);
  int						pregMatch(const std::string &str, const std::string &good) const;
  int						countChar(const std::string &str, const char c) const;
  void						splitToVectors(const std::string &line, const char c);
  std::map<int, std::string>			getGrammar() const;
  void						setGrammar(std::map<int, std::string> grammar);
  void						displayVectors() const;
  void						displayVectors(std::vector<std::vector<std::string> > tokens) const;
  std::vector<std::vector<std::string> >	getTokens() const;
  std::string					removeSpaces(std::string &str) const;
  void						checkGrammar();
  void						checkGrammar(std::vector<std::vector<std::string> > tokens);
  bool						checkPositionOfStringInStr(const std::string &str, const std::string &needle, const size_t pos) const;
  void						clearTokens();
private:
  Parser					_parser;
  std::vector<std::vector<std::string> >	_tokens;
  std::map<int, std::string>			_grammar;
};

#endif
