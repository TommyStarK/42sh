/*
** setenv.c for 42sh in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/chambo_e/setenv
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Mon May 12 16:41:23 2014 chambon emmanuel
** Last update Sun May 25 20:24:17 2014 chambon emmanuel
*/

#include "42.h"

int		print_usage_setenv()
{
  fprintf(stderr, ARG_SETENV);
  return (0);
}

char		*get_new_value(char *item, char *value)
{
  char		*ret;

  if (!((ret = my_xmalloc((strlen(item) + strlen(value) + 2) * sizeof(char)))))
    return (NULL);
  bzero(ret, (strlen(item) + strlen(value) + 2));
  strcat(ret, item);
  strcat(ret, "=");
  strcat(ret, value);
  return (ret);
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
      sh->env[i] = get_new_value(item, value);
      return (0);
    }
  else
    {
      free(sh->env[i]);
      sh->env[i] = get_new_value(item, value);
      return (0);
    }
  fprintf(stderr, PB_ENV);
  return (-1);
}

int		check_is_dollar(char *value)
{
  int		i;

  i = 0;
  while (value[i])
    {
      if (value[i] == '$')
	{
	  fprintf(stderr, INVALID_VALUE, value);
	  return (-1);
	}
      i++;
    }
  return (0);
}

int		my_setenv(char **opt, t_sh *sh)
{
  char		*item;
  char		*value;

  if (!opt[0] || tab_len(opt, NULL) != 2)
    return (print_usage_setenv());
  if (check_is_dollar(opt[1]))
    return (0);
  item = strdup(opt[0]);
  value = strdup(opt[1]);
  if ((add_item(item, value, sh)))
    {
      sh->misc.last_return = 1;
      free(item);
      free(value);
      return (0);
    }
  free(item);
  free(value);
  return (0);
}
