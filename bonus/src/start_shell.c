/*
** main.c for minishell1 in /home/vicostudio/Shared/Rendu/PSU/PSU_2015_minishell1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Tue Jan 12 18:23:26 2016 victor sousa
** Last update Fri Mar 25 11:22:14 2016 Victor Sousa
*/

#include	"corewar.h"

void		pid_son(t_session *session, t_cmd *cmd)
{
  int		i;
  t_node	*cmd_list;
  t_node	*tmp;

  i = 0;
  while (is_the_one("PATH", session->usr_env[i]) == 0)
    i++;
  cmd_list = load_exec_list(session->usr_env[i]);
  tmp = cmd_list;
  while (tmp != NULL && my_strcmp(cmd->exec, tmp->exec) == 0)
    tmp = tmp->next;
  if (tmp == NULL ||
      execve(tmp->full_path, cmd->arg, session->usr_env) == -1)
    print_unknow_cmd(cmd->exec);
  free_list(cmd_list);
}

void		treat_cmd(t_cmd *cmd, t_session *session)
{
  int		pid;
  int		pid_stat;

  if (my_strcmp(cmd->exec, "exit") == 1)
    modular_prog_status(1, -1);
  else if (my_strcmp(cmd->exec, "setenv") == 1)
    my_setenv(*cmd, session->usr_env);
  else if (my_strcmp(cmd->exec, "unsetenv") == 1)
    my_unsetenv(*cmd, session->usr_env);
  else if (my_strcmp(cmd->exec, "run") == 1 ||
	   my_strcmp(cmd->exec, "corewar") == 1)
    {
      if ((pid=fork()) == 0)
	start_corewar(tablen(cmd->arg), cmd->arg, session->usr_env);
      else
	waitpid(pid, &pid_stat, 0);
    }
  else if ((pid=fork()) == 0)
    pid_son(session, cmd);
  else
    waitpid(pid, &pid_stat, 0);
}

int		main_loop_shell(t_session session)
{
  char		*str;
  t_cmd		cmd;

  my_putprompt(&session);
  str = get_next_line(0);
  if (str)
    {
      cmd = parse_str(str);
      modular_prog_status(1, 1);
      treat_cmd(&cmd, &session);
      free(cmd.exec);
      free_wordtab(cmd.arg);
    }
  if (modular_prog_status(0, 0) == -1)
    {
      free_session(&session);
      return (0);
    }
  free(str);
  return (1);
}

int		start_shell(int ac, char *av[], char *env[])
{
  t_session	session;

  (void)ac;
  (void)av;
  if (env == NULL)
    return (-1);
  if (init_session(&session, env) == -1)
    return (-1);
  clear_scr();
  signal(SIGINT, sighandler);
  while (main_loop_shell(session) == 1);
  return (0);
}
