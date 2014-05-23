/*
** main.c for 42sh in /home/milox_t/Dropbox/42sh/groupe_milox/milox_t
**
** Made by thomas milox
** Login   <milox_t@epitech.net>
**
** Started on  Tue May 13 18:01:59 2014 thomas milox
** Last update Thu May 22 23:01:16 2014 chambon emmanuel
*/

#include "42.h"

void		print_tree(t_bin *tree)
{
  t_bin		*tmp;
  int		i;

  tmp = tree;
  if (tmp->cmd)
    {
      i = 0;
      while (tmp->cmd[i])
	printf("##### cmd :%s ###############\n", tmp->cmd[i++]);
    }
  else
    printf("###### operator :%s  #############\n", tmp->op);
  if (tmp->l)
    print_tree(tmp->l);
  if (tmp->r)
    print_tree(tmp->r);
}
