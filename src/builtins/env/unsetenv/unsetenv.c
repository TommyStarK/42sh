/*
** unsetenv.c for minishell1 in /home/chambo_e/Dropbox/tek1/rendu/PSU_2013_minishell1
**
** Made by emmanuel chambon
** Login   <chambo_e@epitech.net>
**
** Started on  Thu Dec 26 17:37:22 2013 emmanuel chambon
** Last update Sun May 25 20:26:12 2014 chambon emmanuel
*/

#include "42.h"

void            *print_usage_unsetenv()
{
  fprintf(stderr, ARG_UNSET);
  return (NULL);
}

char		**paste_env(t_sh *sh, int i)
{
  char		**new_env;
  int		x;
  int		y;

  y = 0;
  x = 0;
  if (!(new_env = my_xmalloc((tab_len(sh->env, NULL)) * sizeof(char *))))
    return (NULL);
  new_env[tab_len(sh->env, NULL) - 1] = NULL;
  while (sh->env[x])
   {
     if (x == i)
       x++;
     new_env[y] = strdup(sh->env[x]);
     x++;
     y++;
   }
  free_tab(sh->env);
  return (new_env);
}

int		my_unsetenv(char **opt, t_sh *sh)
{
  int		i;

  if (!opt[0] || tab_len(opt, NULL) > 1)
    print_usage_unsetenv();
  i = check_present(opt[0], sh->env);
  if (i == -1)
    {
      sh->misc.last_return = 1;
      fprintf(stderr, NT_FND_ENV);
      return (0);
    }
  else
   {
     if (!(sh->env = paste_env(sh, i)))
       return (0);
     return (0);
   }
  return (0);
}
