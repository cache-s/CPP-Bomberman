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

  luaL_openlibs(L);
  if (luaL_loadfile(L, "./sources/scripts/hello.lua") || lua_pcall(L, 0, 0, 0))
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
  if (lua_pcall(L, 0, 0, 0) != 0)
    {
      std::cerr<< "Error running function \"hw\": " << lua_tostring(L, -1) << std::endl;
      return (-1);
    }
  lua_pop(L, 1);
  lua_close(L);
  return 0;
}
