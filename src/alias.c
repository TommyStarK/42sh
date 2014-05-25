/*
** alias.c for 42sh in /home/sarda_j/Dropbox/42sh/groupe_milox/sarda_j/
**
** Made by chambon emmanuel
** Login   <sarda_j@epitech.net>
**
** Started on  Mon May 19 21:47:02 2014 chambon emmanuel
** Last update Sun May 25 09:31:22 2014 chambon emmanuel
*/

#include "42.h"

char		*replace_alias(char *line, t_sh *sh, int i, t_alias *tmp)
{
  char		**cmd;
  char		*ret;

  if (!(cmd = my_str_to_wordtab(line, ' ')))
    return (line);
  tmp = sh->alias;
  while (tmp)
    {
      i = 0;
      while (cmd[i])
	{
	  if (!(strcmp(cmd[i], tmp->alias)))
	    {
	      free(cmd[i]);
	      cmd[i] = strdup(tmp->replace);
	    }
	  i++;
	}
      tmp = tmp->next;
    }
  if (!(ret = strcat_dat(cmd)))
    return (line);
  free(line);
  free_tab(cmd);
  return (ret);
}
