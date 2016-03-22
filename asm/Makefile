##
## Makefile for  in /home/kerdel_e/rendu/mathematics/101pong
##
## Made by ethan kerdelhue
## Login   <kerdel_e@epitech.net>
##
## Started on  Mon Nov  9 10:51:49 2015 ethan kerdelhue
## Last update Tue Mar 22 18:43:11 2016 Kerdelhue Ethan
##

 CC = gcc -g

 RM = rm -f

 CFLAGS += -Wextra -Wall -Werror
 CFLAGS += -pedantic
 CFLAGS += -I./inc/ -g3

 LDFLAGS =

 NAME =  asm

 SRCS = 	op.c    			\

 SRCS +=  	parsing/read_file.c  		\
		parsing/parse_instr.c  		\
		parsing/parseArguments.c 	\
		parsing/parse_args.c		\
		parsing/parse_label.c		\
		parsing/parse_mem.c		\
		parsing/get_args.c  		\

SRCS  += 	check/check_name.c		\
		check/check_commentary.c	\
		check/check_comment.c		\
		check/check_label.c		\
		check/check_op.c		\
		check/check_string.c		\

SRCS  +=       	writing/write_header.c  	\
		writing/open_cor_file.c  	\
		writing/write_instr.c		\
		writing/write_args.c		\
		writing/write_byte_param.c	\
		writing/write_cor_file.c	\

SRCS  += 	utils/get_next_line.c  		\
		utils/epur_cw.c			\
		utils/string.c   		\
		utils/my_strcat.c		\
	   	utils/my_getnbr.c  		\
		utils/my_strncpy.c  		\
		utils/int_tobyte.c  		\
		utils/my_memset.c  		\
		utils/my_str_to_wordtab.c 	\
		utils/linked_list.c  		\
		utils/compare.c   		\
		utils/xfunctions.c 		\

 OBJS = $(SRCS:.c=.o)

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
