/*
** shell.h for corewar in /Users/sousa_v/Shared/rendu/cpe/Coreware_temp/bonus/includes/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Fri Mar 25 10:08:38 2016 Victor Sousa
** Last update Fri Mar 25 10:40:53 2016 Victor Sousa
*/

#ifndef		_SHELL_H_
# define	_SHELL_H_

# define	KNRM  "\x1B[0m"
# define	KRED  "\x1B[31m"
# define	KGRN  "\x1B[32m"
# define	KYEL  "\x1B[33m"
# define	KBLU  "\x1B[34m"
# define	KMAG  "\x1B[35m"
# define	KCYN  "\x1B[36m"
# define	KWHT  "\x1B[37m"

# ifndef        READ_SIZE
#  define       READ_SIZE       (1)
# endif     /* !READ_SIZE */

typedef struct  s_session
{
  char          *usr_name;
  char          *usr_pwd;
  char          *usr_short_pwd;
  char          **usr_env;
}               t_session;

typedef struct  s_cmd
{
  char          *exec;
  char          **arg;
}               t_cmd;

typedef struct  s_node
{
  char          *exec;
  char          *full_path;
  struct s_node *next;
}               t_node;

/*  sources/env_parsing  */
char            **get_env(char **src);
char            *get_user(char **env);
char            *get_pwd(char **env);
char            *get_short_pwd(char *pwd);

/*  sources/cmd  */
void            my_setenv(t_cmd cmd, char **env);
void            my_unsetenv(t_cmd cmd, char **env);

/*  sources/misc  */
void            clear_scr();
char            *my_strcpy(char *dest, char *src);
char            *my_strcat(char *dest, char *src);
int             my_strcmp(char *s1, char *s2);
int             my_strlen(char *str);
int             tablen(char **tab);
int             is_the_one(char *name, char *line);
char            **my_str_to_wordtab(char *str);
void            free_wordtab(char **str);
char            *get_next_line(const int fd);
int             init_session(t_session *session, char **env);
void            free_session(t_session *session);
char            *get_exec(char *str);
t_node          *load_exec_list(char *full_path);
void            free_list(t_node *list);
t_cmd           parse_str(char *str);
void            sighandler(int sig);
void            *xmalloc(int size);

/*  sources/modular  */
int             modular_prog_status(char boolean, int value);

/*  sources/print */
void            my_putchar(char c);
void            my_putstr(char *str);
void            my_putprompt(t_session *session);
void            print_unknow_cmd(char *str);

#endif	      /*_SHELL_H_*/
