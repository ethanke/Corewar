##
## Makefile for corewar in /home/vicostudio/rendu/cpe/CorewarGIT/corewar
##
## Made by victor sousa
## Login   <sousa_v@epitech.net>
##
## Started on  Mon Feb 29 22:36:30 2016 victor sousa
## Last update Thu Mar 17 06:04:52 2016 victor sousa
##

NAME		=	corewar

SRCDIR		=	src
OUTPUTDIR	=	$(SRCDIR)/output
PRINTFDIR	=	$(OUTPUTDIR)/my_printf
LOADINGDIR	=	$(SRCDIR)/loading
UTILSDIR	=	$(SRCDIR)/utils
FUNCTDIR	=	$(SRCDIR)/funct
LOOPDIR		=	$(SRCDIR)/loop

CFLAGS		=	-I../includes -I./includes
CFLAGS		+=	-lSDL -lSDL_image -lSDL_ttf
CFLAGS		+= 	-Wall -Wextra -Werror -pedantic -g -g3

CC		=	gcc
RM		=	rm -f

SRC		=	$(SRCDIR)/main.c			\
			$(SRCDIR)/end.c				\
			$(SRCDIR)/op.c

SRC		+=	$(OUTPUTDIR)/my_putchar_error.c		\
			$(OUTPUTDIR)/my_putstr_error.c		\
			$(OUTPUTDIR)/print_arena.c

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

SRC		+=	$(LOADINGDIR)/init_champion.c		\
			$(LOADINGDIR)/init_arena.c		\
			$(LOADINGDIR)/load_champion.c		\
			$(LOADINGDIR)/fill_process.c		\
			$(LOADINGDIR)/id_stuff.c		\
			$(LOADINGDIR)/get_header.c		\
			$(LOADINGDIR)/get_instruct.c

SRC		+=	$(UTILSDIR)/params.c			\
			$(UTILSDIR)/verif_arg.c			\
			$(UTILSDIR)/my_getnbr.c			\
			$(UTILSDIR)/list.c			\
			$(UTILSDIR)/xmalloc.c			\
			$(UTILSDIR)/xopen.c			\
			$(UTILSDIR)/calculs.c			\
			$(UTILSDIR)/my_memset.c			\
			$(UTILSDIR)/registre.c			\
			$(UTILSDIR)/oct_verif.c			\
			$(UTILSDIR)/color.c

SRC		+=	$(FUNCTDIR)/check.c			\
			$(FUNCTDIR)/fork.c			\
			$(FUNCTDIR)/ld.c			\
			$(FUNCTDIR)/st.c			\
			$(FUNCTDIR)/add.c			\
			$(FUNCTDIR)/ldi.c			\
			$(FUNCTDIR)/disp_func.c

SRC		+=	$(LOOPDIR)/loop.c			\
			$(LOOPDIR)/loop2.c			\
			$(LOOPDIR)/sdl_init.c			\
			$(LOOPDIR)/sdl_print.c

OBJ		=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
			@$(RM) $(OBJ)

fclean:			clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
