##
## Makefile for corewar in /home/vicostudio/rendu/cpe/CorewarGIT/corewar
##
## Made by victor sousa
## Login   <sousa_v@epitech.net>
##
## Started on  Mon Feb 29 22:36:30 2016 victor sousa
## Last update Mon Mar  7 01:27:33 2016 victor sousa
##

NAME		=	corewar

SRCDIR		=	src
OUTPUTDIR	=	$(SRCDIR)/output
LOADINGDIR	=	$(SRCDIR)/loading
UTILSDIR	=	$(SRCDIR)/utils

CFLAGS		=	-I../includes
CFLAGS		+=	-Iincludes
CFLAGS		+= 	-Wall -Wextra -Werror -pedantic

CC		=	gcc
RM		=	rm -f

SRC		=	$(SRCDIR)/main.c

SRC		+=	$(OUTPUTDIR)/my_putchar.c	\
			$(OUTPUTDIR)/my_putstr.c	\
			$(OUTPUTDIR)/my_putchar_error.c	\
			$(OUTPUTDIR)/my_putstr_error.c

SRC		+=	$(LOADINGDIR)/load_champion.c

SRC		+=	$(UTILSDIR)/endian.c		\
			$(UTILSDIR)/verif_arg.c		\
			$(UTILSDIR)/my_strlen.c

OBJ		=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
## A RM ##
			@$(RM) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
