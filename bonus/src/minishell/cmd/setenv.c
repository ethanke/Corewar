/*
** setenv.c for minishell1 in /home/vicostudio/Shared/Rendu/PSU/PSU_2015_minishell1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Sun Jan 24 19:04:17 2016 victor sousa
** Last update Fri Mar 25 10:19:44 2016 Victor Sousa
*/

#include		"corewar.h"

void			my_setenv(t_cmd cmd, char **env)
{
  int			y;
  int			len;

  if (tablen(cmd.arg) != 3)
    {
      my_putstr("must be setenv [NAME] [VALUE]\n");
      return;
    }
  y = 0;
  while (env[y])
    {
      if ((len = is_the_one(cmd.arg[1], env[y])) != 0)
	{
	  free(env[y]);
	  env[y] = xmalloc(sizeof(char) * (my_strlen(cmd.arg[1]
						     + my_strlen(cmd.arg[2]) + 3)));
	  my_strcpy(env[y], cmd.arg[1]);
	  my_strcat(env[y], "=");
	  my_strcat(env[y], cmd.arg[2]);
	  return;
	}
      y++;
    }
  my_putstr("failed\nvar name not found in env\n");
  return;
}
