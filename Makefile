##
## C:\Users\Guillaume\Documents\GitHub\CoreWAR\Makefile for  in
##
## Made by Guillaume SAGOT
## Login   <sagot_g@epitech.eu>
##
## Started on  Mon Feb 22 17:23:09 2016 Guillaume SAGOT
## Last update Mon Feb 29 15:13:11 2016 Guillaume SAGOT
##

COMP		=	gcc

CFLAGS		+=	-Werror -Wextra -Wall -W
CFLAGS		+=	-ansi -pedantic
CFLAGS		+=	-Iinclude

SRCPRNTF	=       sources/print/main.c                            \
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

clean		:
			rm -f $(OBJASM)

fclean		:	clean
			rm -f $(NAMEASM)

re		:	fclean all

.PHONY		:	all clean fclean re
