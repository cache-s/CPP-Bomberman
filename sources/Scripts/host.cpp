extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include		<iostream>

int			main()
{
  lua_State*		L = luaL_newstate();
  int			z;

  luaL_openlibs(L);
  if (luaL_loadfile(L, "./hello.lua") || lua_pcall(L, 0, 0, 0))
    {
      std::cerr << "Error: " << lua_tostring(L, -1) << std::endl;
      return (-1);
    }
  lua_getglobal(L, "hw");
  if(!lua_isfunction(L,-1))
    {
      lua_pop(L,1);
      return (-1);
    }
  if (lua_pcall(L, 0, 1, 0) != 0)
    {
      std::cerr<< "Error running function \"hw\": " << lua_tostring(L, -1) << std::endl;
      return (-1);
    }

  if (!lua_isnumber(L, -1))
    std::cerr << "Function 'hw' must return a number" << std::endl;
  z = lua_tonumber(L, -1);
  lua_pop(L, 1);
  std::cout << "Nombre reçu du lua : " << z << std::endl;
  return z;
}
