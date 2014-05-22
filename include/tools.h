/*
** tools.h for tools in /home/milox_t/rendu/PSU_2013_minishell1
**
** Made by thomas milox
** Login   <milox_t@epitech.net>
**
** Started on  Thu Dec 26 22:44:04 2013 thomas milox
** Last update Thu May 22 23:39:05 2014 chambon emmanuel
*/

#ifndef TOOLS_H_
# define TOOLS_H_

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_it
{
  int		i;
  int		j;
  int		size;
}		t_it;

int		my_strcmp(char *, char *);
int		my_strncmp(char *, char *, int);
int		my_strlen(char *);
int		my_getnbr(char *);
char            *epur_str(char *);
char		*my_strncpy(char *, char *, int);
void		my_putchar(char);
void		my_putchar_error(char);
void		my_puterror(char *);
void		xfree(char **);
/* get_next_line */
char		*my_realloc(char *, int);
void		new_buff(char[], int, int);
char		*nxt_line(char *, const int, char[], t_it *);
char		*gt_next_line(const int );
/* str_wtab */
int		word_len(char *);
int		nb_words(char *);
void		my_ncpy(char *, int, char *);
char		**str_wtab(char *);
#endif /* ! TOOLS_H_ */
