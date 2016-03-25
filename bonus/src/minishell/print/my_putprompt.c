/*
** my_putprompt.c for minishell1 in /mnt/hgfs/Shared/Rendu/PSU/PSU_2015_minishell1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Mon Jan 18 13:35:31 2016 victor sousa
** Last update Fri Mar 25 10:13:51 2016 Victor Sousa
*/

#include		"corewar.h"

void		my_putprompt(t_session *session)
{
  my_putstr(session->usr_name);
  my_putstr(KGRN);
  my_putstr(" @ ");
  my_putstr(KNRM);
  my_putstr(session->usr_short_pwd);
  my_putstr(KGRN);
  my_putstr(" -> ");
  my_putstr(KNRM);
}
