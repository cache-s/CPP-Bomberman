//
// ParserExceptions.cpp for  in /home/bourma_m/Projet/C++/cpp_plazza
// 
// Made by Mathieu Bourmaud
// Login   <bourma_m@epitech.net>
// 
// Started on  Tue Apr 21 10:42:58 2015 Mathieu Bourmaud
// Last update Thu Apr 23 17:06:38 2015 Mathieu Bourmaud
//

#include		"ParserExceptions.hh"

ParserExceptions::ParserExceptions(const std::string &msg) : domain_error(msg), _msg(msg)
{
}
