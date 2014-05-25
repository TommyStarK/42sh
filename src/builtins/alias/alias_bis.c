/*
** alias_bis.c for 42 in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/PSU_2013_42sh/src/builtins
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sun May 25 21:14:37 2014 chambon emmanuel
** Last update Sun May 25 21:15:01 2014 chambon emmanuel
*/

#include "42.h"

int		list_put_start(t_alias **list, char *alias, char *replace)
{
  t_alias	*new_elem;

  if (!(new_elem = my_xmalloc(sizeof(t_alias))))
    return (-1);
  new_elem->alias = alias;
  new_elem->replace = replace;
  new_elem->next = *list;
  *list = new_elem;
  return (0);
}
