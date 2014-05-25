/*
** tools.h for tools in /home/milox_t/rendu/PSU_2013_minishell1
**
** Made by thomas milox
** Login   <milox_t@epitech.net>
**
** Started on  Thu Dec 26 22:44:04 2013 thomas milox
** Last update Sat May 24 00:29:55 2014 chambon emmanuel
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

char            *epur_str(char *);
char		*my_strncpy(char *, char *, int);
/* get_next_line */
char		*my_realloc(char *, int);
void		new_buff(char[], int, int);
char		*nxt_line(char *, const int, char[], t_it *);
char		*gt_next_line(const int );
#endif /* ! TOOLS_H_ */
