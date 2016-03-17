##
## C:\Users\Guillaume\Documents\GitHub\CoreWAR\Makefile for  in
##
## Made by Guillaume SAGOT
## Login   <sagot_g@epitech.eu>
##
## Started on  Mon Feb 22 17:23:09 2016 Guillaume SAGOT
## Last update Thu Mar 17 02:52:19 2016 victor sousa
##

all:
		make -C asm/
		make -C corewar/
		make -C bonus/

clean:
		make clean -C asm/
		make clean -C corewar/
		make clean -C bonus/


fclean:
		make fclean -C asm/
		make fclean -C corewar/
		make fclean -C bonus/

re:		fclean	all

.PHONY:		all clean fclean re
