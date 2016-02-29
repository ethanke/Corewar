##
## Makefile for corewar in /home/vicostudio/rendu/cpe/CorewarGIT/corewar
## 
## Made by victor sousa
## Login   <sousa_v@epitech.net>
## 
## Started on  Mon Feb 29 22:36:30 2016 victor sousa
## Last update Mon Feb 29 22:36:34 2016 victor sousa
##

NAME		=	corewar

SRCDIR		=	src

CFLAGS		=	-I../includes/includes_corewar/
CFLAGS		+= 	-Wall -Wextra -Werror -pedantic 

CC		=	gcc
RM		=	rm -f

SRC		=	$(SRCDIR)/main.c		\

OBJ		=	$(SRC:.c=.o)

all	:	$(NAME) clean

$(NAME)	: 	$(OBJ)
		@$(CC) -o $(NAME) $(OBJ)

%.o	:	%.c
		@tput setaf 3
		@tput bold
		@printf "Compiling @ -W -Wextra -Werror "
		@tput setaf 4
		@printf "%s\n" $(patsubst $(RACINE)/%,%,$^)
		@$(CC) $(CFLAGS) -c -o $@ $^
		@tput sgr0
		@tput cuf 68
		@tput cuu1
		@printf "[ "
		@tput setf 2
		@tput bold
		@printf "ok"
		@tput sgr0
		@printf " ]\n"

clean	:
		@$(RM) $(OBJ)
		@tput setaf 3
		@tput bold
		@printf "Removing \t "
		@tput setaf 4
		@printf " File [.o]...\n"
		@tput sgr0
		@tput cuf 68
		@tput cuu1
		@printf "[ "
		@tput setaf 2
		@tput bold
		@printf "ok"
		@tput sgr0
		@printf " ]\n"

fclean	:	 clean
		@$(RM) $(NAME)
		@tput setaf 3
		@tput bold
		@printf "Removing \t "
		@tput setaf 4
		@printf " File %s...\n", $(NAME)
		@tput sgr0
		@tput cuf 67
		@tput cuu1
		@printf "[ "
		@tput setaf 2
		@tput bold
		@printf "ok"
		@tput sgr0
		@printf " ]\n"

re	: 	fclean all

.PHONY	: 	all clean fclean re
