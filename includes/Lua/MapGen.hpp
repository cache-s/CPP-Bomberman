//
// MapGen.hpp for  in /home/charie_p/rendu/cpp_bomberman/includes/Lua
//
// Made by Pierre Charie
// Login   <charie_p@epitech.net>
//
// Started on  Wed May 27 11:40:48 2015 Pierre Charie
// Last update Mon Jun  8 18:23:19 2015 Pierre Charie
//

#ifndef		MAPGEN_HPP_
#define		MAPGEN_HPP_

# include	<stdlib.h>     /* srand, rand */

# include	"Bomberman.hpp"
# include	"AEntity.hpp"
# include	"Factory.hpp"
# include	"IEntity.hpp"

class MapGen
{
public:
  MapGen();
  ~MapGen();
  std::string							luaMapLoad(std::string fileLoad, std::string functionName);
  std::map<std::pair<int, int>, IEntity<glm::vec3> *>		mapGenerate(int width, int height);
  std::map<std::pair<int, int>, IEntity<glm::vec3> *>		playerMapGenerate(int playerNbr);
private:
  void								spawnPlayer(int posX, int posY);
  void								checkPlayerZone(int posX, int posY, int sizeX, int sizeY);
  void                                                          spawnRandomPlayer(int playerNbr);

  int								_width;
  int								_height;
  std::map<std::pair<int, int>, IEntity<glm::vec3> *>		_map;
  std::map<std::pair<int, int>, IEntity<glm::vec3> *>		_pMap;

  Factory							<glm::vec3>_fac;
};

#endif
