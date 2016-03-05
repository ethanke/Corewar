##
## Makefile for corewar in /home/vicostudio/rendu/cpe/CorewarGIT/corewar
## 
## Made by victor sousa
## Login   <sousa_v@epitech.net>
## 
## Started on  Mon Feb 29 22:36:30 2016 victor sousa
## Last update Sat Mar  5 20:01:06 2016 victor sousa
##

NAME		=	asm

SRCDIR		=	src
INSTRUDIR	=	$(SRCDIR)/instructions
PRINTDIR	=	$(SRCDIR)/my_printf
OPERATORDIR	=	$(SRCDIR)/operator
UTILSDIR	=	$(SRCDIR)/utils

CFLAGS		=	-I../includes/includes_asm/
CFLAGS		+= 	-Wall -Wextra -Werror -pedantic

CC		=	gcc
RM		=	rm -f

SRC		=	$(SRCDIR)/main.c			\

SRC		+=	$(INSTRUDIR)/instructions_errors.c	\
			$(INSTRUDIR)/instructions_first.c	\
			$(INSTRUDIR)/tab_instruction.c		\

SRC		+=	$(PRINTFDIR)/flags_one.c		\
			$(PRINTFDIR)/flags_second.c		\
			$(PRINTFDIR)/flags_third.c		\
			$(PRINTFDIR)/library_display.c		\
			$(PRINTFDIR)/library_display_two.c	\
			$(PRINTFDIR)/library_multiusage.c	\
			$(PRINTFDIR)/my_printf.c		\

SRC		+=	$(OPERATORDIR)/op.c			\

SRC		+=	$(UTILSDIR)/xfunction.c			\

OBJ		=	$(SRC:.c=.o)

all:			$(NAME) clean

$(NAME):		$(OBJ)
			$(CC) -o $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
