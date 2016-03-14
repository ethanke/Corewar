##
## C:\Users\Guillaume\Documents\GitHub\CoreWAR\Makefile for  in
##
## Made by Guillaume SAGOT
## Login   <sagot_g@epitech.eu>
##
## Started on  Mon Feb 22 17:23:09 2016 Guillaume SAGOT
## Last update Mon Mar 14 16:50:46 2016 
##

all:
		make -s -C asm/
		make -s -C corewar/

clean:
		make clean -s -C asm/
		make clean -s -C corewar/


fclean:
		make fclean -s -C asm/
		make fclean -s -C corewar/

re:		fclean	all

.PHONY:		all clean fclean re
