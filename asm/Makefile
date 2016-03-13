##
## Makefile for  in /home/kerdel_e/rendu/mathematics/101pong
##
## Made by ethan kerdelhue
## Login   <kerdel_e@epitech.net>
##
## Started on  Mon Nov  9 10:51:49 2015 ethan kerdelhue
## Last update Fri Mar 11 12:42:50 2016 Kerdelhue Ethan
##

CC	= gcc -g

RM	= rm -f

CFLAGS += -Wextra -Wall #-Werror
CFLAGS += -pedantic
CFLAGS += -Iinc -g3

LDFLAGS =

NAME	= asm

SRCS	= 	parsing/read_file.c		\
		parsing/checkName.c		\
		parsing/checkComment.c		\
		utils/get_next_line.c		\
		utils/string.c			\

OBJS	= $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean :
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@
