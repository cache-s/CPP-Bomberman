//
// main.cpp for  in /home/bourma_m/Projet/C++/XML
// 
// Made by Mathieu Bourmaud
// Login   <bourma_m@epitech.net>
// 
// Started on  Fri May 15 15:26:09 2015 Mathieu Bourmaud
// Last update Sun Jun 14 22:54:49 2015 Mathieu Bourmaud
//

#ifndef		_XMLWRITER_H_
# define	_XMLWRITER_H_

#include	<map>
#include	<fstream>
#include	<iostream>
#include	<string>
#include	"Factory.hpp"
#include	"Settings.hpp"

template	<class T>
class		XMLWriter
{
public:
  XMLWriter();
  void		setDocPath(const std::string &path);
  void		addElem(IEntity<T> &ent, std::ofstream &myfile);
  void		addSettings(const Settings &settings, std::ofstream &myfile);
  void		fillDoc(std::map<std::pair<int, int>, IEntity<T> *> &entMap, std::map<std::pair<int, int>, IEntity<T> *> &charMap, const Settings &settings);
private:
  std::string			_path;
  std::map<eEntityType, int>	_nbObj;
  std::map<eEntityType, std::string> _enumToStr;
  Factory<T>			*_factory;
};

template <typename T>
XMLWriter<T>::XMLWriter()
{
  _path = "save.xml";
  _enumToStr[FLOOR] = "floor";
  _enumToStr[BRKWALL] = "brkwall";
  _enumToStr[UBRKWALL] = "ubrkwall";
  _enumToStr[MAPWALL] = "mapwall";
  _enumToStr[BBOMBNUMBER] = "bbombnumber";
  _enumToStr[BSPEED] = "bspeed";
  _enumToStr[BRADIUS] = "bradius";
  _enumToStr[PLAYER] = "player";
  _enumToStr[ARTINT] = "AI";
  _nbObj[FLOOR] = 0;
  _nbObj[BRKWALL] = 0;
  _nbObj[UBRKWALL] = 0;
  _nbObj[MAPWALL] = 0;
  _nbObj[BBOMBNUMBER] = 0;
  _nbObj[BSPEED] = 0;
  _nbObj[BRADIUS] = 0;
  _nbObj[PLAYER] = 0;
  _nbObj[ARTINT] = 0;
  _factory = new Factory<T>();
}

template <typename T>
void			XMLWriter<T>::setDocPath(const std::string &path)
{
  _path = path;
}

template <typename T>
void			XMLWriter<T>::addElem(IEntity<T> &ent, std::ofstream &myfile)
{
  myfile << "<" << _enumToStr[ent.getType()] << _nbObj[ent.getType()] << ">\n<x>" << std::to_string(ent.getPosX()) << "<x/>\n<y>" << std::to_string(ent.getPosY()) << "<y/>\n";
  // if (ent.getType() == PLAYER)
  //   myfile << "\n" << "<bombStock>" << std::to_string(reinterpret_cast<IPlayer<T> >(ent).getBombStock()) << "<bombStock/>\n" << "<radius>" << std::to_string(reinterpret_cast<IPlayer<T> >(ent).getRadius()) << "<radius/>";
  myfile << "<" << _enumToStr[ent.getType()] << _nbObj[ent.getType()] << "/>\n";
  _nbObj[ent.getType()] += 1;
}

template <typename T>
void			XMLWriter<T>::addSettings(const Settings &settings, std::ofstream &myfile)
{
  myfile << "<Settings>\n<score>" << settings.getScore() << "<score/>\n<playerNumber>" << settings.getPlayerNumber() << "<playerNumber/>\n<aiNumber>" << settings.getAINumber() << "<aiNumber/>\n<mapSize>" << settings.getMapSize() << "<mapSize/>\n<name>" << settings.getName() << "<name/>\n" << "<Settings/>";
}

template <typename T>
void			XMLWriter<T>::fillDoc(std::map<std::pair<int, int>, IEntity<T> *> &entMap, std::map<std::pair<int, int>, IEntity<T> *> &charMap, const Settings &settings)
{
  
  std::ofstream myfile;
  typename std::map<std::pair<int, int>, IEntity<T> *>::const_iterator it_e;
  typename std::map<std::pair<int, int>, IEntity<T> *>::const_iterator it_p;
  
  myfile.open("save.xml");
  addSettings(settings, myfile);
  it_e = entMap.begin();
  for (it_e = entMap.begin(); it_e != entMap.end(); it_e++)
    {
      if (it_e->second != NULL)
	addElem(*it_e->second, myfile);
      else
	addElem(*(_factory->createEntity(FLOOR, std::get<0>(it_e->first), std::get<1>(it_e->first))), myfile);
    }
  it_p = charMap.begin();
  for (it_p = charMap.begin(); it_p != charMap.end(); it_p++)
    if (it_p->second != NULL)
      addElem(*it_p->second, myfile);
  myfile.close();
}

#endif
