/*
** user.c for minishell1 in /mnt/hgfs/Shared/Rendu/PSU/PSU_2015_minishell1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Tue Jan 12 21:07:10 2016 victor sousa
** Last update Fri Mar 25 10:11:51 2016 Victor Sousa
*/

#include	"corewar.h"

char	*get_pwd(char **env)
{
  int	i;
  char	*pwd;

  i = 0;
  while (env[i])
    {
      if (env[i][0] == 'P' &&
	  env[i][1] == 'W' &&
	  env[i][2] == 'D' &&
	  env[i][3] == '=')
	{
	  pwd = xmalloc(sizeof(char) * (my_strlen(env[i] + 4) + 1));
	  my_strcpy(pwd, env[i] + 4);
	  return (pwd);
	}
      i++;
    }
  return (NULL);
}
