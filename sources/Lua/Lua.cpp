//
// Lua.cpp for  in /home/charie_p/rendu/cpp_bomberman/sources/Lua
//
// Made by Pierre Charie
// Login   <charie_p@epitech.net>
//
// Started on  Wed May 27 11:31:12 2015 Pierre Charie
// Last update Wed May 27 11:31:13 2015 Pierre Charie
//

std::map<std::make_pair(int x, int y), IEntity entity> mapGenerate(int width, int height)
{
  std::string   mapLua;
  int           i = 0;
  int           x, y = 0;
  std::map<std::make_pair(int x, int y), IEntity entity> gameMap;

  //mapLua = generateMap(width, height); TODO linker avec la fonction LUA

  while (mapLua[i])
    {
      switch (mapLua[i])
        {
        case 0: //sol
          break;
        case 1: //mur destructible
          //      gameMap[x][y] = ;
          break;
        case 2: //mur indestructible
          //gameMap[x][y] = ;
          break;
        case 3: //bord de map
          //gameMap[x][y] = ;
          break;
        }
      x++;
      if (x == width)
        {
          x = 0;
          height++;
        }
    }
}
