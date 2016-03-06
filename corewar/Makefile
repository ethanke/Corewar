##
## Makefile for corewar in /home/vicostudio/rendu/cpe/CorewarGIT/corewar
##
## Made by victor sousa
## Login   <sousa_v@epitech.net>
##
## Started on  Mon Feb 29 22:36:30 2016 victor sousa
## Last update Sun Mar  6 23:43:17 2016 victor sousa
##

NAME		=	corewar

SRCDIR		=	src
UTILSDIR		=	$(SRCDIR)/utils

CFLAGS		=	-I../includes
CFLAGS		+=	-Iincludes
CFLAGS		+= 	-Wall -Wextra -Werror -pedantic

CC		=	gcc
RM		=	rm -f

SRC		=	$(SRCDIR)/main.c

SRC		+=	$(UTILSDIR)/endian.c		\
			$(UTILSDIR)/verif_arg.c

OBJ		=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
