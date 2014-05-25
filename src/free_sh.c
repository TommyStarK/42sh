/*
** free_sh.c for 42sh in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/final_build
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Tue May 20 22:17:50 2014 chambon emmanuel
** Last update Sun May 25 05:53:58 2014 chambon emmanuel
*/

#include "42.h"

void		free_tab(char **t)
{
  int		i;

  i = 0;
  while (t && t[i])
    {
      free(t[i]);
      i++;
    }
  free(t);
}

void		free_alias(t_alias *alias)
{
  t_alias	*tmp;

  while (alias)
    {
      tmp = alias;
      alias = alias->next;
      if (tmp->alias)
	free(tmp->alias);
      if (tmp->replace)
	free(tmp->replace);
      free(tmp);
    }
}

void		free_sh(t_sh *sh)
{
  if (sh)
    {
      if (sh->env)
	free_tab(sh->env);
      if (sh->prompt)
	free(sh->prompt);
      if (sh->alias)
	free_alias(sh->alias);
    }
}
