##
## C:\Users\Guillaume\Documents\GitHub\CoreWAR\Makefile for  in
##
## Made by Guillaume SAGOT
## Login   <sagot_g@epitech.eu>
##
## Started on  Mon Feb 22 17:23:09 2016 Guillaume SAGOT
## Last update Sat Mar  5 20:03:40 2016 victor sousa
##

all:
		make -C asm/
		make Bonus -C corewar/

clean:
		make clean -C asm/


fclean:
		make fclean -C asm/

re:		fclean	all

.PHONY:		all clean fclean re
