/*
** get_env.c for 42sh in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/final_build
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Tue May 20 22:03:22 2014 chambon emmanuel
** Last update Sun May 25 15:02:08 2014 chambon emmanuel
*/

#include "42.h"

char		**minimal_env()
{
  char		**env;

  if (!(env = my_xmalloc(2 * sizeof(char *))))
    return (NULL);
  env[1] = NULL;
  if (!(env[0] = strdup("SHELL=TOMMYSTARK")))
    return (NULL);
  return (env);
}

char		**get_env(char **env)
{
  int		i;
  char		**envp;

  i = 0;
  if (!env || !env[0])
    return (minimal_env());
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
	  fprintf(stderr, ERR_MALLOC);
	  return (NULL);
	}
      i++;
    }
  return (envp);
}
