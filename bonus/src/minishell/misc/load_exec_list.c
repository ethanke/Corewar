/*
** load_exec_list.c for minishell1 in /mnt/hgfs/Shared/Rendu/PSU/PSU_2015_minishell1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Sun Jan 24 20:53:29 2016 victor sousa
** Last update Fri Mar 25 10:12:57 2016 Victor Sousa
*/

#include		"corewar.h"

t_node			*add(t_node *list, char *name, char *beg)
{
  t_node		*newelem;

  newelem = xmalloc(sizeof(t_node));
  newelem->full_path = xmalloc(sizeof(char) *
			  (my_strlen(name) + my_strlen(beg) + 2));
  newelem->full_path = my_strcpy(newelem->full_path, beg);
  newelem->full_path = my_strcat(newelem->full_path, "/");
  newelem->full_path = my_strcat(newelem->full_path, name);
  newelem->exec = xmalloc(sizeof(char) * (my_strlen(name) + 1));
  newelem->exec = my_strcpy(newelem->exec, name);
  newelem->next = list;
  return (newelem);
}

int			count_path(char *full)
{
  int			j;
  int			i;

  j = 0;
  i = 1;
  while (full[j])
    {
      if (full[j] == ':')
	i++;
      j++;
    }
  return (i);
}

int			nextdot(char *str)
{
  int			i;

  i = 0;
  while (str[i] && str[i] != ':')
    i++;
  return (i);
}

char			**get_path(char *full)
{
  int			i;
  int			j;
  int			k;
  int			count;
  char			**out;

  i = 0;
  while (full[i] != '=')
    i++;
  count = count_path(full + i++ + 1);
  out = xmalloc(sizeof(char *) * (count + 1));
  j = 0;
  while (j < count)
    {
      k = 0;
      out[j] = xmalloc(sizeof(char) * (nextdot(full + i) + 1));
      while (full[i] && full[i] != ':')
	out[j][k++] = full[i++];
      i++;
      out[j][k] = '\0';
      j++;
    }
  out[j] = '\0';
  return (out);
}

t_node			*load_exec_list(char *full_path)
{
  t_node		*cmd_list;
  char			**path;
  int			i;
  DIR			*file;
  struct dirent		*dir;

  path = get_path(full_path);
  i = 0;
  cmd_list = NULL;
  while (path[i])
    {
      file = opendir(path[i]);
      while ((dir = readdir(file)) != NULL)
	{
	  cmd_list = add(cmd_list, dir->d_name, path[i]);
	}
      i++;
    }
  free_wordtab(path);
  return (cmd_list);
}
