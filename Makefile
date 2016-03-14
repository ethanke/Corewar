##
## C:\Users\Guillaume\Documents\GitHub\CoreWAR\Makefile for  in
##
## Made by Guillaume SAGOT
## Login   <sagot_g@epitech.eu>
##
## Started on  Mon Feb 22 17:23:09 2016 Guillaume SAGOT
## Last update Mon Mar 14 14:25:16 2016 victor sousa
##

all:
		make -C asm/
		make -C corewar/

clean:
		make clean -C asm/
		make clean -C corewar/


fclean:
		make fclean -C asm/
		make fclean -C corewar/

re:		fclean	all

.PHONY:		all clean fclean re
