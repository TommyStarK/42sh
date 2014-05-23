/*
** get_env.c for 42sh in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/final_build
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Tue May 20 22:03:22 2014 chambon emmanuel
** Last update Tue May 20 22:10:35 2014 chambon emmanuel
*/

#include "42.h"

char		**get_env(char **env)
{
  int		i;
  char		**envp;

  i = 0;
  while (env[i])
    i++;
  if (!(envp = my_xmalloc((i + 1) * sizeof(char *))))
    return (NULL);
  envp[i] = NULL;
  i = 0;
  while (env[i])
    {
      if (!(envp[i] = strdup(env[i])))
	{
	  fprintf(stderr, MALLOC_ERROR);
	  return (NULL);
	}
      i++;
    }
  return (envp);
}
