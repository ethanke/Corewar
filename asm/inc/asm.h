/*
** asm.h for  in /home/kerdel_e/Shared/Corewar/ethan/inc
**
** Made by Kerdelhue Ethan
** Login   <kerdel_e@epitech.net>
**
** Started on  Sun Mar  6 20:19:55 2016 Kerdelhue Ethan
** Last update Tue Mar 22 23:44:58 2016 Ethan Kerdelhue
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
#define STRTWTB			" ,\t\n\"'"
#define LABEL_CHARS             "abcdefghijklmnopqrstuvwxyz_0123456789"
#define NAME_CMD_STRING         ".name"
#define COMMENT_CMD_STRING      ".comment"
#define REG_NUMBER      	16
/*
**	COREWAR ARG'S
*/
#define T_REG         		1
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

typedef char    		args_type_t;
typedef struct 	op_s     	op_t;
typedef struct 	header_s 	t_header;

typedef struct s_corarg
{
  char				*value;
  int				type;
}				t_corarg;

typedef struct 			s_corline
{
  char				*label;
  char				*instruction;
  char				**args;
  int				nbr;
  int				mempos;
  t_corarg			*tab_args;
  struct s_corline		*next;
  struct s_corline		*prev;
}				t_corline;

typedef struct			s_corlabel
{
  int				mempos;
  char				*name;
  struct s_corlabel		*next;
}				t_corlabel;

typedef struct 			s_cor
{
  int				fd;
  char				*name;
  char				**tab;
  t_corline			*first_line;
  t_corlabel			*first_label;
}				t_cor;

typedef struct          	header_s
{
  int                   	magic;
  char                  	prog_name[PROG_NAME_LENGTH+1];
  int                   	prog_size;
  char                  	comment[COMMENT_LENGTH+1];
}                       	header_t;

struct  op_s
{
  char         			*mnemonique;
  char         			nbr_args;
  args_type_t  			type[MAX_ARGS_NUMBER];
  char         			code;
  int          			nbr_cycles;
  char         			*comment;
};

typedef union           	u_int4char
{
  int                   	nbr;
  unsigned char         	str[4];
}                       	t_int4char;

typedef union           	u_int2char
{
  int                   	nbr;
  unsigned char         	str[2];
}                       	t_int2char;

typedef union           	u_intchar
{
  int                   	nbr;
  unsigned char         	str;
}                       	t_intchar;

extern  	op_t    	op_tab[];

	/* PARSING */
int				calc_mem_pos(t_corline *tmp,
					     t_corline *corline);
void				create_corline_l(t_corline tmp,
						 t_corline *corline,
						 t_corlabel *corlabel,
						 op_t op);
void				create_corline_wl(t_corline tmp,
						  t_corline *corline,
						  op_t op);
int				get_mem_size(t_corarg *tab_args);
int 				parse_instr(t_cor *corfile);
int				start_parse_instr(t_corline *corline,
						  t_corlabel *corlabel,
						  char *str);
int	 			parse_header(t_cor *corfile);
char				*line_is_label(char *args);
op_t				checkOp(char *mnemonic);
t_corarg			*get_args(char **tab, int i);
int				count_args(char **tab);
char    			*get_next_line(const int fd);

	/* CHECK FUNC	*/
void				checkCommentLine(char **tab);
int				containCommentChar(char *str);
void				convert_label_value(t_corlabel *label,
						    t_corline *corline);
int				get_label_value(t_corlabel *label, char *str);
int				checkLabExist(t_corlabel *label, char *str);
int				is_alph_char(char c, char *delim);
int				my_str_isalpha(char *str);
char				*checkComment(char *str, t_header *header);
char				*checkName(char *str, t_header *header);
char				*checkLabel(char *name);

	/* LINK LIST FUNC */
t_corline			*corline_init();
void				create_line(t_corline *corline,
					    t_corline line);
t_corlabel			*corlabel_init();
void				create_label(t_corlabel *corlabel,
					     t_corlabel label);

	/* OPEN FUNC */
void				open_corfile(t_cor *corfile);
char				*getCorName(char *str);

	/* Writing Func */
void				write_instr(int nbr, int fd, t_corarg *args);
void				write_byte_param(int fd, t_corarg *args);
void				write_header(t_header *header, t_cor *corfile);
void				write_cor(t_cor *corfile);
void				write_args_wpb(int fd, t_corarg *args);
void				write_args(int fd, t_corarg *args);
void				put_param(int nbr, int bit, int fd);

	/* READ */
int				read_file(char	*file);

	/* UTILS */
char 				*my_strcat(char *dest, char *src);
int				my_char_is_num(char c);
char				*epur_cw(char *str);
char				*my_itoa(int nb);
char				*epur_cw(char *str);
void            		*xmalloc(int size);
int				my_getnbr(char *str);
int				my_strcmp(char *s1, char *s2);
char				*my_strcpy(char *dest, char *src);
char				**my_str_to_wordtab(char *str, char *delim);
int				int_to4byte(int data);
char				*my_strncpy(char *dest, char *src, int n);
void				my_putchar(char c);
void  				*my_memset(void *s, size_t n, int c);
void				putError(char *str);
int				my_strlen(char *str);
void				my_putstr(char *str);

#endif
