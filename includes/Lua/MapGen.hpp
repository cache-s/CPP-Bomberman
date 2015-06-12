//
// MapGen.hpp for  in /home/charie_p/rendu/cpp_bomberman/includes/Lua
//
// Made by Pierre Charie
// Login   <charie_p@epitech.net>
//
// Started on  Wed May 27 11:40:48 2015 Pierre Charie
// Last update Fri Jun 12 17:02:21 2015 Pierre Charie
//

#ifndef		MAPGEN_HPP_
#define		MAPGEN_HPP_

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

# include	<stdlib.h>     /* srand, rand */

# include	"Bomberman.hpp"
# include	"AEntity.hpp"
# include	"Factory.hpp"
# include	"IEntity.hpp"

template <typename T>
class MapGen
{
public:
  MapGen();
  ~MapGen();
  std::string							luaMapLoad(std::string fileLoad, std::string functionName);
  std::map<std::pair<int, int>, IEntity<T> *>		mapGenerate(int width, int height);
  std::map<std::pair<int, int>, IEntity<T> *>		playerMapGenerate(int playerNbr);
  std::map<std::pair<int, int>, IEntity<T> *>		getMap() const;
  std::map<std::pair<int, int>, IEntity<T> *>		getPMap() const;
private:
  void								spawnPlayer(int posX, int posY);
  void								checkPlayerZone(int posX, int posY, int sizeX, int sizeY);
  void                                                          spawnRandomPlayer(int playerNbr);
  void								spawnTwoPlayer();
  void								spawnThreePlayer();
  void								spawnFourPlayer();
  void								spawnFivePlayer();
  void								spawnManyPlayer();

  void								spawnTwoTopLeft();
  void								spawnTwoTopRight();
  void								spawnTwoBottomLeft();
  void								spawnTwoBottomRight();

  void								spawnThreeTopLeft();
  void								spawnThreeTopRight();
  void								spawnThreeBottomLeft();
  void								spawnThreeBottomRight();

  int								_width;
  int								_height;
  int								_playerNbr;
  std::map<std::pair<int, int>, IEntity<T> *>		_map;
  std::map<std::pair<int, int>, IEntity<T> *>		_pMap;
  typedef void (MapGen::*spawnP)();
  std::map<int, spawnP>						_spawnM;

  typedef void (MapGen::*spawnTwoP)();
  std::map<int, spawnP>                                         _spawnTwoM;

  typedef void (MapGen::*spawnThreeP)();
  std::map<int, spawnP>                                         _spawnThreeM;


  Factory							<T>_fac;
};

#include "MapGen.tpp"

#endif
