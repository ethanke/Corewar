##
## C:\Users\Guillaume\Documents\GitHub\CoreWAR\Makefile for  in
##
## Made by Guillaume SAGOT
## Login   <sagot_g@epitech.eu>
##
## Started on  Mon Feb 22 17:23:09 2016 Guillaume SAGOT
## Last update Mon Feb 29 22:05:25 2016 victor sousa
##

COMP		=	gcc

CFLAGS		+=	-Werror -Wextra -Wall -W
CFLAGS		+=	-ansi -pedantic
CFLAGS		+=	-Iinclude

SRCPRNTF	=       sources/print/main.c				\
			sources/print/my_printf.c                       \
			sources/print/library_display.c                 \
			sources/print/library_display_two.c             \
			sources/print/library_multiusage.c              \
			sources/print/flags_one.c                       \
			sources/print/flags_second_part.c               \
			sources/print/flags_third_part.c                \

SRCASM		=	sources/asm/instructions/tab_instruction.c	\
			sources/asm/instructions/instructions_first.c	\

SRCVM		=	sources/vm/

NAMEASM		=	asm

NAMEVM		=	virtual_machine

OBJASM		=	$(SRCASM:.c=.o)

all		:	$(NAMEASM)

$(NAMEASM)	:	$(OBJASM)
			$(COMP) $(SRCASM) -o $(NAMEASM) $(CFLAGS)

clean   :
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

fclean  :	clean
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

c.o     :
		@tput setaf 3
		@tput bold
		@printf "Compiling @ -W -Wextra -Werror "
		@tput setaf 4
		@printf "%s\n" $(patsubst $(RACINE)/%,%,$^)
		@$(CC) $(CFLAGS) -D$(LIB) -c -o $@ $^
		@tput sgr0
		@tput cuf 68
		@tput cuu1
		@printf "[ "
		@tput setf 2
		@tput bold
		@printf "ok"
		@tput sgr0
		@printf " ]\n"

re		:	fclean all

.PHONY		:	all clean fclean re
