/*
** short_pwd.c for minishell1 in /mnt/hgfs/Shared/Rendu/PSU/PSU_2015_minishell1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Wed Jan 13 02:37:33 2016 victor sousa
** Last update Fri Mar 25 10:11:56 2016 Victor Sousa
*/

#include	"corewar.h"

char		*get_short_pwd(char *pwd)
{
  int	i;
  int	lenght;
  char	*short_pwd;

  lenght = 0;
  i = my_strlen(pwd);
  while (pwd[i--] != '/')
    lenght++;
  short_pwd = xmalloc(sizeof(char) * (lenght + 1));
  my_strcpy(short_pwd, pwd + i + 2);
  return (short_pwd);
}
