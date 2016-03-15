/*
** funct.h for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/includes/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sun Mar 13 11:44:48 2016 Gaëtan Léandre
** Last update Tue Mar 15 18:01:53 2016 Gaëtan Léandre
*/

#ifndef		FUNCT_H_
# define	FUNCT_H_

int		check_arg(int funct, int pos, char arg);
int		check_reg(int reg);
int		check_mult_args(unsigned char *arena, int fun,
				int pos, int siz);

#endif	      /*FUNCT_H_*/
