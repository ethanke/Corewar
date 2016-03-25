/*
** session.c for minishell1 in /mnt/hgfs/Shared/Rendu/PSU/PSU_2015_minishell1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Sun Jan 24 03:23:19 2016 victor sousa
** Last update Fri Mar 25 10:13:24 2016 Victor Sousa
*/

#include		"corewar.h"

int             init_session(t_session *session, char **env)
{
  if ((session->usr_env = get_env(env)) == NULL)
    return (-1);
  if ((session->usr_name = get_user(session->usr_env)) == NULL)
    return (-1);
  if ((session->usr_pwd = get_pwd(session->usr_env)) == NULL)
    return (-1);
  if ((session->usr_short_pwd = get_short_pwd(session->usr_pwd)) == NULL)
    return (-1);
  return (0);
}

void            free_session(t_session *session)
{
  free(session->usr_name);
  free(session->usr_pwd);
  free(session->usr_short_pwd);
  free_wordtab(session->usr_env);
}
