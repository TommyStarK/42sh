/*
** alias.c for 42 in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/PSU_2013_42sh/src/builtins/alias
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sat May 24 06:17:27 2014 chambon emmanuel
** Last update Sat May 24 18:41:47 2014 chambon emmanuel
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

int		find_quote(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\'')
        return (i);
      i++;
    }
  return (-1);
}

int		check_alias(char *str)
{
  int		i;
  int		quote;
  int		equal;

  i = 0;
  quote = 0;
  equal = 0;
  while (str[i])
    {
      if (str[i] == '\'')
        quote++;
      if (str[i] == '=')
        equal++;
      i++;
    }
  if (quote == 2 && equal == 1)
    return (1);
  else
    return (-1);
}

char		*get_opt(char **opt)
{
  int		i;
  char		*cmd;

  if (!(cmd = strdup(opt[0])))
    {
      fprintf(stderr, ERR_MALLOC);
      return (NULL);
    }
  i = 1;
  while (opt[i])
    {
      if (!(cmd = my_strcat(cmd, " ")))
	return (NULL);
      if (!(cmd = my_strcat(cmd, opt[i])))
	return (NULL);
      i++;
    }
  return (cmd);
}

int		print_alias(t_sh *sh)
{
  t_alias	*tmp;

  tmp = sh->alias;
  while (tmp)
    {
      printf("%s='%s'\n", tmp->alias, tmp->replace);
      tmp = tmp->next;
    }
  return (0);
}

int		alias(t_sh *sh, char **opt)
{
  int           i;
  int           alias_size;
  char          *alias;
  char          *replace;
  char		*cmd;

  i = 0;
  if (!opt[0])
    return (print_alias(sh));
  if (!(cmd = get_opt(opt)))
    return (0);
  if (check_alias(cmd) == -1)
    {
      fprintf(stderr, INVALID_ALIAS);
      return (0);
    }
  while (cmd[i] != '=')
    i++;
  if (!(alias = my_strncpy_m(cmd, i)))
    return (0);
  i += 2;
  if ((alias_size = find_quote(&cmd[i])) == -1)
    {
      fprintf(stderr, INVALID_ALIAS);
      return (0);
    }
  replace = my_strncpy_m(&cmd[i], alias_size);
  if ((list_put_start(&sh->alias, alias, replace)) == -1)
    return (0);
  return (0);
}
