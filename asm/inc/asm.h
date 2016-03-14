/*
** asm.h for  in /home/kerdel_e/Shared/Corewar/ethan/inc
**
** Made by Kerdelhue Ethan
** Login   <kerdel_e@epitech.net>
**
** Started on  Sun Mar  6 20:19:55 2016 Kerdelhue Ethan
** Last update Mon Mar 14 05:24:41 2016 Ethan Kerdelhue
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
#define REG_NUMBER      	16
#define T_REG         		 1
#define T_DIR           	2
#define T_IND           	4
#define T_LAB           	8
#define IND_SIZE        	2
#define REG_SIZE        	4
#define DIR_SIZE        	REG_SIZE
#define PROG_NAME_LENGTH        128
#define COMMENT_LENGTH          2048
#define CYCLE_TO_DIE    	1536
#define CYCLE_DELTA     	5
#define NBR_LIVE        	40
#define COREWAR_EXEC_MAGIC      0xea83f3

typedef char    args_type_t;
typedef struct op_s     op_t;
typedef struct header_s t_header;

typedef struct s_cor
{
  int			fd;
  char			*name;
}			t_cor;

typedef struct          header_s
{
  int                   magic;
  char                  prog_name[PROG_NAME_LENGTH+1];
  int                   prog_size;
  char                  comment[COMMENT_LENGTH+1];
}                       header_t;

struct  op_s
{
   char         	*mnemonique;
   char         	nbr_args;
   args_type_t  	type[MAX_ARGS_NUMBER];
   char         	code;
   int          	nbr_cycles;
   char         	*comment;
};

typedef union           u_int4char
{
  int                   nbr;
  unsigned char         str[4];
}                       t_int4char;

typedef union           u_int2char
{
  int                   nbr;
  unsigned char         str[2];
}                       t_int2char;

typedef union           u_intchar
{
  int                   nbr;
  unsigned char         str;
}                       t_intchar;

/* PARSING */

char	*checkComment(char *str, t_header *header);
char	*checkName(char *str, t_header *header);
int 	parse_header(char **tab, t_cor *corfile);


/* OPEN FUNC */
void	open_corfile(t_cor *corfile);
char	*getCorName(char *str);

/* Writing Func */
void	write_header(t_header *header, t_cor *corfile);

/* READ */
int	read_file(char	*file);

/* UTILS */
int	int_tobyte(int data);
char	*my_strncpy(char *dest, char *src, int n);
void	my_putchar(char c);
void    *my_memset(void *s, size_t n, int c);
void	putError(char *str);
int	my_strlen(char *str);
void	my_putstr(char *str);
#endif
