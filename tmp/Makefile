##
## Makefile for  in /home/bourma_m/Projet/C++/cpp_bomberman
## 
## Made by Mathieu Bourmaud
## Login   <bourma_m@epitech.net>
## 
## Started on  Wed Apr 29 10:53:42 2015 Mathieu Bourmaud
## Last update Wed Apr 29 11:01:11 2015 Mathieu Bourmaud
##

SRC		=	./sources/Main.cpp		\
			./sources/tools/Lexer.cpp	\
			./sources/tools/Parser.cpp	\
			./sources/tools/LexerExceptions.cpp \
			./sources/tools/ParserExceptions.cpp \

OBJ		=	$(SRC:.cpp=.o)

CC		=	g++

INC		=	./includes

CPPFLAGS	=	-I $(INC)
CPPFLAGS	+=	-W -Wall -Werror -Wextra

LDFLAGS		=	-lpthread

NAME		=	bomberman

RM		=	rm -f

$(NAME)		:	$(OBJ)
			$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

all		:	$(NAME)

clean		:
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all
