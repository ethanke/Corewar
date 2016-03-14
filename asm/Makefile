##
## Makefile for  in /home/kerdel_e/rendu/mathematics/101pong
##
## Made by ethan kerdelhue
## Login   <kerdel_e@epitech.net>
##
## Started on  Mon Nov  9 10:51:49 2015 ethan kerdelhue
## Last update Mon Mar 14 16:11:55 2016 Guillaume SAGOT
##

CC	= clang -g

RM	= rm -f

CFLAGS += -Wextra -Wall -Werror
CFLAGS += -pedantic
CFLAGS += -I./inc/ -g3

LDFLAGS =

NAME	= 	asm

SRCS	= 	parsing/read_file.c		\
		parsing/checkName.c		\
		parsing/checkComment.c		\
		parsing/parse_instr.c		\
		parsing/checkLabel.c		\
		parsing/parseArguments.c	\

SRCS 	+=	writing/write_header.c		\
		writing/open_cor_file.c		\

SRCS 	+=	utils/get_next_line.c		\
		utils/string.c			\
		utils/my_strncpy.c		\
		utils/int_tobyte.c		\
		utils/my_memset.c		\
		utils/my_str_to_wordtab.c	\
		utils/linked_list.c		\
		utils/compare.c			\

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
