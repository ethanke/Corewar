/*
** corewar.h for corewar in /home/vicostudio/rendu/cpe/CorewarGIT/corewar
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Mon Feb 29 22:25:56 2016 victor sousa
** Last update Fri Mar 25 17:21:21 2016 victor sousa
*/

#ifndef			COREWAR_H_
# define		COREWAR_H_

# include		<unistd.h>
# include		<stdlib.h>
# include		<signal.h>
# include               <sys/types.h>
# include		<sys/wait.h>
# include               <sys/stat.h>
# include		<fcntl.h>
# include		<dirent.h>
# include		<SDL/SDL.h>
# include		<SDL/SDL_image.h>
# include		<SDL/SDL_ttf.h>

# include		"shell.h"
# include		"op.h"
# include		"champ.h"
# include		"arena.h"
# include		"funct.h"
# include		"loop.h"
# include		"utils.h"
# include		"output.h"
# include		"my_printf.h"
# include		"loading.h"

# define		FONT_PATH	"font/ultraviolentbbitalic.ttf"
# define		SERVER_FILE	"vm_stat.json"

int			start_shell(int ac, char **av, char **env);
int			start_corewar(int ac, char **av, char **env);

#endif		      /*COREWAR_H*/
