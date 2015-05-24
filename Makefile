##
## Makefile for bomber in /home/cache-_s/rendu/cpp_bomberman
## 
## Made by Sebastien Cache-Delanos
## Login   <cache-_s@epitech.net>
## 
## Started on  Wed May 13 11:07:19 2015 Sebastien Cache-Delanos
## Last update Sun May 24 17:57:33 2015 Martin Porrès
##

NAME	= bomberman

SRCS	= ./sources/main.cpp				\
	  ./sources/GUI/GDLGUI.cpp			\
	  ./sources/GUI/AssetsManager.cpp		\
	  ./sources/Thread/CondVar.cpp			\
	  ./sources/Thread/Mutex.cpp			\
	  ./sources/Thread/ScopedLock.cpp		\
	  ./sources/Thread/Task.cpp			\
	  ./sources/Thread/Thread.cpp			\

OBJS	= $(SRCS:.cpp=.o)

INCS		+= -Iincludes -Iincludes/GUI -Iincludes/AI -Iincludes/Audio -Iincludes/Entity -Iincludes/LibBomberman/includes -Iincludes/Thread -Lincludes/LibBomberman/libs -Wl,-rpath=./includes/LibBomberman/libs/

CXXFLAGS	+= -W -Wall -Wextra -Werror $(INCS)

LUAFLAGS	+= lua/lua-5.3.0/install/lib/liblua.a -I lua/lua-5.3.0/install/include/ -ldl

GDLFLAGS	+= -lgdl_gl -lGLEW -lfbxsdk -lGL -ldl -lrt -lSDL2 -lpthread

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
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LUAFLAGS) $(GDLFLAGS)
	@echo -n 'Finished building target:'
	@echo -e $(GREEN) '$@'
	@echo -e $(NORMAL) ' '

%.o: %.cpp
	@echo ' '
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(LUAFLAGS) $(GDLFLAGS)
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

re: fclean all
