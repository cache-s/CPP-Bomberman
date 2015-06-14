//
// XMLReader.hpp for  in /home/bourma_m/Projet/C++/XML
// 
// Made by Mathieu Bourmaud
// Login   <bourma_m@epitech.net>
// 
// Started on  Mon May 18 16:45:36 2015 Mathieu Bourmaud
// Last update Sun Jun 14 22:50:38 2015 Mathieu Bourmaud
//

#ifndef		_XMLREADER_HPP_
# define	_XMLREADER_HPP_

#include	<stdexcept>
#include	<sys/stat.h>
#include	<fstream>
#include	<sstream>
#include	<string>
#include	<iostream>
#include	"tinyxml2.h"
#include	"XMLWriter.hpp"

class		XMLReader
{
public:
  XMLReader();

  bool			isDirectory(const char *file)
  {
    struct stat		mystat;
    
    stat(file, &mystat);
    return (S_ISDIR(mystat.st_mode));
  }

  bool			checkFile(const char *file)
  {
    std::ifstream		myfile(file, std::ifstream::in);
        
    try
      {
	if (isDirectory(file) == true)
	  throw std::runtime_error("Can't read a directory");
	if (!myfile.is_open())
	  throw std::runtime_error("Invalid file.");
      }
    catch (const std::runtime_error &e)
      {
	std::cerr << "Error : " << e.what() << std::endl;
	return (false);
      }
    myfile.close();
    return (true);
  }

  int getValueOf(const char *node, const char *elem, tinyxml2::XMLDocument &doc)
  {
    doc.LoadFile("save.xml");
    if (doc.FirstChildElement(node) == NULL)
      throw std::runtime_error("The XML file is wrong...Don't try to cheat by changing it.");
    if (doc.FirstChildElement(node)->FirstChildElement(elem) == NULL)
      throw std::runtime_error("The XML file is wrong...Don't try to cheat by changing it.");
    title = doc.FirstChildElement(node)->FirstChildElement(elem)->GetText();
    printf( "Name of play (1): %s\n", title);
    // tinyxml2::XMLText* textNode = doc.FirstChildElement( "PLAY" )->FirstChildElement( "TITLE" )->FirstChild()->ToText();
    // title = textNode->Value();
    // printf( "Name of play (2): %s\n", title );
    return (0);
  }

  void parseFile()
  {
    try
      {
	tinyxml2::XMLDocument doc;
	const char * title;
	
	if (checkFile("save.xml"))
	  {
	    
	  }
      }
    catch (const std::exception &e)
      {
	std::cerr << "Error : " << e.what() << std::endl;
      }
    }
  
private:
  std::string			_path;
  std::map<std::pair<int, int>, IEntity<T> *> _charMap;
  std::map<std::pair<int, int>, IEntity<T> *> _entMap;
};

#endif
