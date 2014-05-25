/*
** history.c for 42 in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/PSU_2013_42sh/src/builtins
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sun May 25 09:00:43 2014 chambon emmanuel
** Last update Sun May 25 09:01:12 2014 chambon emmanuel
*/

#include "42.h"

int		show_history(t_hist *list)
{
  int		i;
  t_hist	*tmp;

  i = 0;
  tmp = list;
  while (tmp != NULL)
    {
      i++;
      printf("  %d\t%s\n", i, tmp->str);
      tmp = tmp->next;
    }
  return (0);
}
