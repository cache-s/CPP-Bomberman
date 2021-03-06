##
## Makefile for bomber in /home/cache-_s/rendu/cpp_bomberman
## 
## Made by Sebastien Cache-Delanos
## Login   <cache-_s@epitech.net>
## 
## Started on  Wed May 13 11:07:19 2015 Sebastien Cache-Delanos
## Last update Sun Jun 14 22:11:00 2015 Mathieu Bourmaud
##

NAME	= bomberman

SRCS	= ./sources/main.cpp				\
	  ./sources/GUI/AssetsManager.cpp		\
	  ./sources/Thread/CondVar.cpp			\
	  ./sources/Thread/Mutex.cpp			\
	  ./sources/Thread/Thread.cpp			\
	  ./sources/Thread/ScopedLock.cpp		\
	  ./sources/Menu/MenuStart.cpp			\
	  ./sources/Menu/MenuSettings.cpp		\
	  ./sources/Menu/MenuLoad.cpp			\
	  ./sources/Menu/MenuSave.cpp			\
	  ./sources/Menu/MenuPause.cpp			\
	  ./sources/Menu/MenuScore.cpp			\
	  ./sources/Menu/MenuEnd.cpp			\
	  ./sources/Settings.cpp			\

OBJS	= $(SRCS:.cpp=.o)

INCS	+= -Iincludes -IXML/ -Iincludes/Thread/ -Iincludes/Entity/Environment/ -Iincludes/Entity/Character/ -Iincludes/GUI -Iincludes/Factory -Iincludes/AI -Iincludes/Menu -Iincludes/Entity -Iincludes/LibBomberman/includes -Iincludes/Thread -Lincludes/LibBomberman/libs -Iincludes/Lua -Iincludes/Core -Iincludes/Manager -Wl,-rpath=./includes/LibBomberman/libs/

CXXFLAGS	+= -W -Wall -Wextra -Werror -Wno-uninitialized $(INCS)

LUAFLAGS	+= lua/lua-5.3.0/install/lib/liblua.a -I lua/lua-5.3.0/install/include/ -ldl

GDLFLAGS	+= -lgdl_gl -lGLEW -lfbxsdk -lGL -ldl -lrt -lSDL2 -lpthread -std=c++0x

SOUNDFLAGS      += -lsfml-system -lsfml-audio

CXX	= g++

RM	= rm -f

GREEN	= "\\033[1;32m"

NORMAL	= "\\033[0;39m"

YELLOW	= "\\033[1;33m"

all:	$(NAME)

$(NAME): $(OBJS)
	@echo ' '
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	$(CXX) $(CXXFLAGS) $(SOUNDFLAGS) -o $@ $^ $(LUAFLAGS) $(GDLFLAGS)
	@echo -n 'Finished building target:'
	@echo -e $(GREEN) '$@'
	@echo -e $(NORMAL) ' '

%.o: %.cpp
	@echo ' '
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	$(CXX) $(CXXFLAGS) $(SOUNDFLAGS) -c -o $@ $< $(LUAFLAGS) $(GDLFLAGS)
	@echo -n 'Finished building: '
	@echo -e $(YELLOW) '$<'
	@echo -e $(NORMAL) ' '

clean:
	$(RM) $(OBJS)
	@find ./ -name '*~' -exec rm '{}' \;
	@find ./ -name '*#' -exec rm '{}' \;

fclean: clean
	$(RM) $(NAME)

dbg: CXXFLAGS += -g
dbg: re

cl: CXX = clang++ -Qunused-arguments
cl: re

re: fclean all
