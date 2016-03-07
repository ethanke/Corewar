##
## Makefile for liblapin in /home/leandr_g/rendu/Novembre_2015/noise_2020
## 
## Made by Gaëtan Léandre
## Login   <leandr_g@epitech.net>
## 
## Started on  Fri Nov  6 09:13:30 2015 Gaëtan Léandre
## Last update Fri Nov 13 19:28:37 2015 Gaëtan Léandre
##

NAME		=	libmy.a

FLAGS		=	-W -Wall -Werror -ansi -pendantic

SRC		=	my_printf.c \
			my_printf1.c \
			my_printf2.c \
			my_printf3.c \
			my_putchar.c \
			my_put_u_nbr_base.c \
			my_disp_unprintable.c \
			my_put_nbr.c \
			my_putstr.c \
			my_putnbr_base.c \
			my_put_unbr.c \
			my_putnbr_base_add.c

OBJ		=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ)
			ar cr $(NAME) $(OBJ)
			ranlib $(NAME)

clean:
			rm -f $(OBJ)

fclean:			clean
			rm -f $(NAME)

re:			fclean all
