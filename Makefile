##
## Makefile for bomber in /home/cache-_s/rendu/cpp_bomberman
## 
## Made by Sebastien Cache-Delanos
## Login   <cache-_s@epitech.net>
## 
## Started on  Wed May 13 11:07:19 2015 Sebastien Cache-Delanos
## Last update Fri May 15 15:59:21 2015 Jordan Chazottes
##

NAME	= bomberman

SRCS	= ./sources/scripts/host.cpp			\

OBJS	= $(SRCS:.cpp=.o)

CXXFLAGS	+=  -W -Wall -Wextra -Werror -I ./includes 

LUAFLAGS	+= lua/lua-5.3.0/install/lib/liblua.a -I lua/lua-5.3.0/install/include/ -ldl

CXX	= g++

RM	= rm -f

GREEN	= "\\033[1;32m"

NORMAL	= "\\033[0;39m"

YELLOW	= "\\033[1;33m"

all: $(NAME)

$(NAME): $(OBJS)
	@echo ' '
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	$(CXX) -o $@ $^ $(LUAFLAGS)
	@echo -n 'Finished building target:'
	@echo -e $(GREEN) '$@'
	@echo -e $(NORMAL) ' '

%.o: %.cpp
	@echo ' '
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	$(CXX) -c -o $@ $< $(LUAFLAGS)
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
