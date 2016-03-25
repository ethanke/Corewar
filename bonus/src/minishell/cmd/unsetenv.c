/*
** unsetenv.c for minishell1 in /mnt/hgfs/Shared/Rendu/PSU/PSU_2015_minishell1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Sun Jan 24 19:49:54 2016 victor sousa
** Last update Fri Mar 25 10:19:51 2016 Victor Sousa
*/

#include		"corewar.h"

int			hum(int save, int y, char **env)
{
  save = y++;
  while (y < tablen(env))
    {
      free(env[save]);
      env[save] = xmalloc(sizeof(char) * (my_strlen(env[y]) + 1));
      env[save] = my_strcpy(env[save], env[y++]);
      save++;
    }
  return (save);
}

void			my_unsetenv(t_cmd cmd, char **env)
{
  int			y;
  int			save;

  if (tablen(cmd.arg) != 2)
    {
      my_putstr("must be unsetenv [NAME]\n");
      return;
    }
  y = 0;
  while (y < tablen(env))
    {
      if ((save = is_the_one(cmd.arg[1], env[y])) != 0)
	{
	  save = hum(save, y, env);
	  env[save] = 0;
	  return;
	}
      y++;
    }
  my_putstr("failed\nvar name not found in env\n");
  return;
}
