/*
** user.c for minishell1 in /mnt/hgfs/Shared/Rendu/PSU/PSU_2015_minishell1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Tue Jan 12 21:07:10 2016 victor sousa
** Last update Fri Mar 25 10:12:01 2016 Victor Sousa
*/

#include	"corewar.h"

char	*get_user(char **env)
{
  int	i;
  char	*name;

  i = 0;
  while (env[i])
    {
      if (env[i][0] == 'U' &&
	  env[i][1] == 'S' &&
	  env[i][2] == 'E' &&
	  env[i][3] == 'R' &&
	  env[i][4] == '=')
	{
	  name = xmalloc(sizeof(char) * (my_strlen(env[i] + 5) + 1));
	  my_strcpy(name, env[i] + 5);
	  return (name);
	}
      i++;
    }
  return (NULL);
}
