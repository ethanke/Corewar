##
## Makefile for corewar in /home/vicostudio/rendu/cpe/CorewarGIT/corewar
##
## Made by victor sousa
## Login   <sousa_v@epitech.net>
##
## Started on  Mon Feb 29 22:36:30 2016 victor sousa
<<<<<<< HEAD
## Last update Thu Mar 10 23:39:13 2016 Gaëtan Léandre
##
=======
## Last update Fri Mar 11 00:05:35 2016 Guillaume SAGOT
## Last update Thu Mar 10 15:55:32 2016 Gaëtan Léandre
##
>>>>>>> f5ef25e669c2e6fcab67eef7f49e58a5a26852f1

NAME  		= 	asm

SRCDIR  	= 	src

INSTRUDIR 	= 	$(SRCDIR)/instructions

PRINTDIR 	= 	$(SRCDIR)/my_printf

OPERATORDIR 	= 	$(SRCDIR)/operator

UTILSDIR 	= 	$(SRCDIR)/utils

CFLAGS  	= 	-I../includes/includes_asm/
CFLAGS  	+=  	-Wall -Wextra -Werror -pedantic

CC  		= 	clang
RM  		= 	rm -f

 SRC  		= 	$(SRCDIR)/main.c   					\

 SRC  		+= 	$(INSTRUDIR)/instructions_errors.c 			\
    			$(INSTRUDIR)/instructions_first.c 			\
    			$(INSTRUDIR)/tab_instruction.c  			\
    			$(INSTRUDIR)/register_check.c  				\
    			$(INSTRUDIR)/file_validation.c  			\

 SRC  		+= 	$(PRINTFDIR)/flags_one.c  				\
    			$(PRINTFDIR)/my_printf.c  				\
    			$(PRINTFDIR)/flags_third.c  				\
    			$(PRINTFDIR)/flags_second.c  				\
    			$(PRINTFDIR)/library_display.c  			\
    			$(PRINTFDIR)/library_multiusage.c 			\
    			$(PRINTFDIR)/library_display_two.c 			\

 SRC  		+= 	$(OPERATORDIR)/op.c   					\

 SRC  		+= 	$(UTILSDIR)/library.c   				\
    			$(UTILSDIR)/afferrno.c   				\
    			$(UTILSDIR)/xfunction.c   				\

 OBJ  		= 	$(SRC:.c=.o)

 all 		: 	$(NAME) music clean

 $(NAME) 	:  	$(OBJ)
			@$(CC) -o $(NAME) $(OBJ)

music		:
			@paplay points.ogg

 %.o 		:	%.c @tput setaf 3
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

 clean 		:
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

 fclean 	:  	clean
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

re 		:  	fclean all

.PHONY 		: 	all clean fclean re
