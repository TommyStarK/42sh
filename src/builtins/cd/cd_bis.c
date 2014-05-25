/*
** cd_bis.c for 42 in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/PSU_2013_42sh/src
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sun May 25 01:44:24 2014 chambon emmanuel
** Last update Sun May 25 01:44:41 2014 chambon emmanuel
*/

#include "42.h"

char		*get_item(t_sh *sh, char *item)
{
  int		i;

  i = 0;
  while (sh->env[i])
    {
      if (!strncmp(sh->env[i], item, strlen(item)))
        return (strdup(&sh->env[i][strlen(item)]));
      i++;
    }
  fprintf(stderr, MISSING_ENV, (int)strlen(item) - 1, item);
  return (NULL);
}
