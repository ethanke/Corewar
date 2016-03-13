##
## Makefile for corewar in /home/vicostudio/rendu/cpe/CorewarGIT/corewar
##
## Made by victor sousa
## Login   <sousa_v@epitech.net>
##
## Started on  Mon Feb 29 22:36:30 2016 victor sousa
## Last update Sun Mar 13 11:52:27 2016 Gaëtan Léandre
##

NAME		=	corewar

SRCDIR		=	src
OUTPUTDIR	=	$(SRCDIR)/output
PRINTFDIR	=	$(OUTPUTDIR)/my_printf
LOADINGDIR	=	$(SRCDIR)/loading
UTILSDIR	=	$(SRCDIR)/utils
FUNCTDIR	=	$(SRCDIR)/funct

CFLAGS		=	-I../includes
CFLAGS		+=	-Iincludes
CFLAGS		+= 	-Wall -Wextra -Werror -pedantic -g -g3

CC		=	gcc
RM		=	rm -f

SRC		=	$(SRCDIR)/main.c			\
			$(SRCDIR)/op.c

SRC		+=	$(OUTPUTDIR)/my_putchar_error.c		\
			$(OUTPUTDIR)/my_putstr_error.c

SRC		+=	$(PRINTFDIR)/my_printf.c 		\
			$(PRINTFDIR)/my_printf1.c 		\
			$(PRINTFDIR)/my_printf2.c 		\
			$(PRINTFDIR)/my_printf3.c 		\
			$(PRINTFDIR)/my_putchar.c 		\
			$(PRINTFDIR)/my_put_u_nbr_base.c 	\
			$(PRINTFDIR)/my_disp_unprintable.c 	\
			$(PRINTFDIR)/my_put_nbr.c 		\
			$(PRINTFDIR)/my_putstr.c 		\
			$(PRINTFDIR)/my_putnbr_base.c 		\
			$(PRINTFDIR)/my_put_unbr.c 		\
			$(PRINTFDIR)/my_putnbr_base_add.c

SRC		+=	$(LOADINGDIR)/init_champion.c	\
			$(LOADINGDIR)/load_process.c	\
			$(LOADINGDIR)/id_stuff.c

SRC		+=	$(UTILSDIR)/endian.c		\
			$(UTILSDIR)/params.c		\
			$(UTILSDIR)/verif_arg.c		\
			$(UTILSDIR)/my_getnbr.c		\
			$(UTILSDIR)/list.c		\
			$(UTILSDIR)/xmalloc.c		\
			$(UTILSDIR)/calculs.c

SRC		+=	$(FUNCTDIR)/check.c

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
