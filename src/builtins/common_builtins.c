/*
** common_env.c for 42sh in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/chambo_e/env
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Wed May 14 15:41:26 2014 chambon emmanuel
** Last update Sun May 25 06:09:17 2014 chambon emmanuel
*/

#include "42.h"

int		tab_len(char **t, char *type)
{
  int		i;

  i = 0;
  while (t[i])
    i++;
  if (type)
    {
      if (i > 1 && !strcmp(type, "cd"))
	fprintf(stderr, ARG_CD);
    }
  return (i);
}

int		check_present(char *item, char **env)
{
  int		i;

  i = 0;
  while (env[i])
    {
      if (!strncmp(env[i], item, strlen(item)))
        return (i);
      i++;
    }
  return (-1);
}
