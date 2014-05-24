/*
** setenv.c for 42sh in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/chambo_e/setenv
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Mon May 12 16:41:23 2014 chambon emmanuel
** Last update Thu May 22 17:56:21 2014 chambon emmanuel
*/

#include "42.h"

int		print_usage_setenv()
{
  fprintf(stderr, ARG_SETENV);
  return (0);
}

int		add_item(char *item, char *value, t_sh *sh)
{
  int		i;

  i = check_present(item, sh->env);
  if (i == -1)
    {
      i = tab_len(sh->env, NULL);
      sh->env = realloc(sh->env, (i + 2) * sizeof(char *));
      sh->env[i + 1] = NULL;
      sh->env[i] = strdup(my_strcat(my_strcat(item, "="), value));
      return (0);
    }
  else
    {
      bzero(sh->env[i], strlen(sh->env[i]));
      sh->env[i] = strdup(my_strcat(my_strcat(item, "="), value));
      return (0);
    }
  fprintf(stderr, PB_ENV);
  return (-1);
}

int		my_setenv(char **opt, t_sh *sh)
{
  char		*item;
  char		*value;

  if (!opt[0] || tab_len(opt, NULL) > 2)
    return (print_usage_setenv());
  item = strdup(opt[0]);
  value = strdup(opt[1]);
  if ((add_item(item, value, sh)))
    {
      free(item);
      free(value);
      return (0);
    }
  free(item);
  free(value);
  return (0);
}