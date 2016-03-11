/*
** asm.h for  in /home/kerdel_e/Shared/Corewar/ethan/inc
**
** Made by Kerdelhue Ethan
** Login   <kerdel_e@epitech.net>
**
** Started on  Sun Mar  6 20:19:55 2016 Kerdelhue Ethan
** Last update Fri Mar 11 18:45:31 2016 Ethan Kerdelhue
*/

#ifndef ASM_H_
# define ASM_H_

# include "assembly.h"

/* PARSING */

char	*checkComment(char *str);
char	*checkName(char *str);
int	parse_header(char **tab);

/* READ */

int	read_file(char	*file);

/* UTILS */
void	my_putchar(char c);
void	putError(char *str);
int	my_strlen(char *str);
void	my_putstr(char *str);
#endif
