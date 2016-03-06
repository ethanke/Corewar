/*
** corewar.h for  in /home/sagot/Downloads/corewar/asm/
**
** Made by Guillaume SAGOT
** Login   <sagot_g@epitech.eu>
**
** Started on  Thu Jan 28 14:25:39 2016 Guillaume SAGOT
** Last update Mon Mar  7 00:45:40 2016 Guillaume SAGOT
*/

#ifndef _ASSEMBLY_H_
# define _ASSEMBLY_H_
# define _GNU_SOURCE

/* Header declaration 						*/
# include               <sys/types.h>
# include               <sys/stat.h>
# include               <dirent.h>
# include               <stdlib.h>
# include 		<string.h>
# include               <unistd.h>
# include               <fcntl.h>
# include               <stdio.h>
# include               <time.h>
# include               <pwd.h>
# include               <grp.h>

#include 		"printf.h"

/*****************************************************************\
**	struct defini pour la récuperation des labels		**
/*****************************************************************/

typedef struct          s_label
{
  int                   i;
  int                   fd;
  int                   line;
  char                  *name;
  char			*pos;
  struct s_label	next;
}                       t_label;

/*****************************************************************\
**	struct defini pour la récuperation des instructions	 **
/******************************************************************
/*
	Je la traiterais plus tard mais les seules choses dont tu
	as besoin de savoir sur cette structure, sont les suivantes:
	- i = indenteur (y) tmtc;
	- c =récupère des caracters spéciaux du type ':';
	- ins = nom des instructuions à la structure s_system;
	**
	le reste je sais plus pourquoi je les ai déclaré: mais
	ils doivent avoir une utilité dans un futur proche ;)
*/

typedef struct          s_instruction
{
  int                   i;
  int                   cmptr;
  int                   *ins; /* Principal pointeur de la structure avec i, c, cmptr, str; */
  char			c;
  char                  control;
  char                  *instruction_check;
  char                  *str;
}                       t_instruction;

/*****************************************************************\
**	Main	structure	for 	assembly		**
/*****************************************************************/

/*	appellée dans la structure t_label et t_instruction
	dans t_system sert à facilité  la récupération ds labels,
	et des instructions. Cela va servir à transférer plus
	tard dans la function d'écriture des instructions
*/

typedef struct		s_system
{
  char			**tab; /* tableau de récupèration des \*checkError* et instructions */
  char			*name; /* nom des programme */
  char			*file_name; /* nom des fichiers, */
  char			*ret; /* temporaire, mais il sera utile pour la suite ;) !*/
  char			*str; /* lui c'est un peu le pointeur qui va nous servir au vérifications (tailles/caracters / ..)*/
  int			col; /*pou$ le tableau*/
  int			i; /* ma bite sur ton front ça fait un dindon <3 */
  t_label		label[128]; /* L'appele des pour la récupération des labels, sur une taile en dur, défini dans le op.h */
  t_instruction		instruction; /* Je la surnome la cafetière, cest l'appel de structure qui permet de modaliser les instructuions */
}			t_system;

/* utils functions */
int     	mstrcmp(char *s1, char *s2);
char		*mstrrchr(const char *s, int c);

/* functions for instructions */
void		live_instruction(t_system *sys);
void		load_instruction(t_system *sys);
void		store_instruction(t_system *sys);
void		addition_instruction(t_system *sys);
void		substraction_instruction(t_system *sys);
void		and_instruction(t_system *sys);
void		or_instruction(t_system *sys);
void		xor_instruction(t_system *sys);
void		jump_if_zero_instruction(t_system *sys);
void		load_index_instruction(t_system *sys);
void		store_index_instruction(t_system *sys);
void		fork_instruction(t_system *sys);
void		long_load_instruction(t_system *sys);
void		long_load_index_instruction(t_system *sys);
void		long_fork_instruction(t_system *sys);
void		aff_instruction(t_system *sys);

/* functions check errors */
void		live_checkError(t_system *sys, int *values);
void		load_checkError(t_system *sys, int values);
void		store_checkError(t_system *sys, int *values);
void		addition_checkError(t_system *sys, int *values);
void		substraction_checkError(t_system *sys, int *values);
void		and_checkError(t_system *sys, int *values);
void		or_checkError(t_system *sys, int *values);
void		xor_checkError(t_system *sys, int *values);
void		jump_if_zero_checkError(t_system *sys, int *values);
void 		ldi_checkError(t_system *sys, int *values);
void		 sti_checkError(t_system *sys, int *values);
void		fork_checkError(t_system *sys, int *values);
void		fork_checkError(t_system *sys, int *values);
void		lld_checkError(t_system *sys, int *values);
void		lldi_checkError(t_system *sys, int *values);
void		lfork_checkError(t_system *sys, int *values);
void		aff_checkError(t_system *sys, int * values);

/* functions initialisation for errors and simple instructuions */
void		initError(void*(checkError[16]));
t_system	*initInstructions();

/* functions for the header ü */
int		load_addressLabel(t_label *label, char *str, int i);

/**********************************************************
guillaume.sagot@epitech.eu
/*********************************************************/

#endif
