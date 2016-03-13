/*
** funct.h for corewar in /Users/leandr_g/Documents/Shared folder/Corewar/corewar/includes/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sun Mar 13 11:44:48 2016 Gaëtan Léandre
** Last update Sun Mar 13 11:49:04 2016 Gaëtan Léandre
*/

#ifndef		_FUNCT_
# define	_FUNCT_

int		check_arg(int funct, int pos, char arg);
int		octet_to_read(char arg);
int		check_reg(int reg);
int		check_mult_args(unsigned char *arena, int fun,
				int pos, int siz);

#endif		/* _FUNCT_ */