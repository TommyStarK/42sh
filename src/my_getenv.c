/*
** my_getenv.c for minishell1 in /home/sarda_j/Dropbox/Epitech/rendu/
**
** Made by sarda_j
** Login   <sarda_j@epitech.net>
**
** Started on  Sun Dec 29 16:32:58 2013 sarda_j
** Last update Sun May 25 14:51:36 2014 chambon emmanuel
*/

#include "42.h"

char		*my_getenv(char **my_env, char *var)
{
  int		i;
  char		*env_var;

  i = 0;
  if (!my_env)
    return (var);
  while (strncmp(my_env[i], var, strlen(var)))
    {
      if (!(my_env[i + 1]))
	return (var);
      i++;
    }
  env_var = &my_env[i][(int)strlen(var) + 1];
  return (env_var);
}
