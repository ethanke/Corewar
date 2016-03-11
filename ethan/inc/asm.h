/*
** asm.h for  in /home/kerdel_e/Shared/Corewar/ethan/inc
**
** Made by Kerdelhue Ethan
** Login   <kerdel_e@epitech.net>
**
** Started on  Sun Mar  6 20:19:55 2016 Kerdelhue Ethan
** Last update Fri Mar 11 21:42:29 2016 Ethan Kerdelhue
*/

#ifndef ASM_H_
# define ASM_H_

# include "assembly.h"

#define MEM_SIZE                (6*1024)
#define IDX_MOD                 512
#define MAX_ARGS_NUMBER         4
#define COMMENT_CHAR            '#'
#define LABEL_CHAR              ':'
#define DIRECT_CHAR             '%'
#define SEPARATOR_CHAR          ','
#define LABEL_CHARS             "abcdefghijklmnopqrstuvwxyz_0123456789"
#define NAME_CMD_STRING         ".name"
#define COMMENT_CMD_STRING      ".comment"
#define REG_NUMBER      16
#define T_REG           1
#define T_DIR           2
#define T_IND           4
#define T_LAB           8
#define IND_SIZE        2
#define REG_SIZE        4
#define DIR_SIZE        REG_SIZE
#define PROG_NAME_LENGTH        128
#define COMMENT_LENGTH          2048
#define CYCLE_TO_DIE    1536
#define CYCLE_DELTA     5
#define NBR_LIVE        40

typedef char    args_type_t;
typedef struct op_s     op_t;
typedef struct header_s header_t;

struct header_s
{
   int  magic;
   char prog_name[PROG_NAME_LENGTH+1];
   int  prog_size;
   char comment[COMMENT_LENGTH+1];
};

struct  op_s
{
   char         *mnemonique;
   char         nbr_args;
   args_type_t  type[MAX_ARGS_NUMBER];
   char         code;
   int          nbr_cycles;
   char         *comment;
};

/* PARSING */

char	*checkComment(char *str);
char	*checkName(char *str);
int	parse_header(char **tab);

/* READ */

int	read_file(char	*file);

/* UTILS */
void	my_putchar(char c);
void	putError(char *str);
int	my_strlen(char *str);
void	my_putstr(char *str);
#endif
