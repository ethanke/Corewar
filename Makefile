##
## C:\Users\Guillaume\Documents\GitHub\CoreWAR\Makefile for  in
##
## Made by Guillaume SAGOT
## Login   <sagot_g@epitech.eu>
##
## Started on  Mon Feb 22 17:23:09 2016 Guillaume SAGOT
## Last update Tue Feb 23 14:57:28 2016 Guillaume SAGOT
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

SRCASM		=	asm/list_instruction/tab_instruction.c		\
			asm/list_instruction/list_instruction_first.c	\

SRCVM		=	VM/

NAMEASM		=	asm

NAMEVM		=	vm

$(OBJASM)	=	$(SRCASM:.c=.o)

all		:	$(NAMEASM)

$(NAMEASM)	:	$(OBJASM)
			$(COMP) $(SRCASM) -o $(NAMEASM) $(CFLAGS)

clean		=
			rm -fr $(OBJASM)

fclean		=	clean
			rm -fr $(NAMEASM)

re		=	fclean all

.PHONY		=	all clean fclean re
