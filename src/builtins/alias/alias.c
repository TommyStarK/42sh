/*
** alias.c for 42 in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sat May 24 06:17:27 2014 chambon emmanuel
** Last update Sun May 25 21:16:42 2014 chambon emmanuel
*/

#include "42.h"

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
  int		flag;

  i = 0;
  quote = 0;
  equal = 0;
  flag = 0;
  while (str[i])
    {
      if (str[i] == '\'')
        quote++;
      if (str[i] == '=')
	{
	  if (quote == 0)
	    flag++;
	  equal++;
	}
      i++;
    }
  if (quote == 2 && equal >= 1 && flag == 1)
    return (1);
  else
    return (-1);
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

int		error_alias()
{
  fprintf(stderr, INVALID_ALIAS);
  return (0);
}

int		alias(t_sh *sh, char **opt, int flag, int i)
{
  int           alias_size;
  char          *alias;
  char          *replace;
  char		*cmd;

  if (!opt[0])
    return (print_alias(sh));
  if (!(cmd = strcat_dat(opt)))
    return (0);
  if (check_alias(cmd) == -1)
    return (error_alias());
  while (cmd[i] != '=')
    i++;
  if (!(alias = my_strncpy_m(cmd, i)))
    return (0);
  i += 2;
  if ((alias_size = find_quote(&cmd[i])) == -1
      || !(replace = my_strncpy_m(&cmd[i], alias_size)))
    return (error_alias());
  if ((list_put_start(&sh->alias, alias, replace)) == -1)
    return (0);
  if (flag)
    free_tab(opt);
  free(cmd);
  return (0);
}
