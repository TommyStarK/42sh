/*
** alias.c for 42sh in /home/sarda_j/Dropbox/42sh/groupe_milox/sarda_j/
**
** Made by sarda_j
** Login   <sarda_j@epitech.net>
**
** Started on  Mon May 19 21:47:02 2014 sarda_j
** Last update Sat May 24 18:35:44 2014 chambon emmanuel
*/

#include "42.h"

char		*replace_word(char *buff, t_alias *tmp, int *i)
{
  int		j;
  char		*new_buff;

  j = *i;
  if (!(new_buff = my_xmalloc(sizeof(char) * strlen(tmp->replace) + 1)))
    return (NULL);
  my_strncpy(new_buff, buff, *i);
  new_buff[*i] = '\0';
  strcat(new_buff, tmp->replace);
  strcat(new_buff, &buff[j + strlen(tmp->alias)]);
  *i = *i + (int)strlen(tmp->replace);
  /* free(buff); */
  return (new_buff);
}

char		*replace_alias(char *buff, t_sh *sh)
{
  int		i;
  t_alias	*tmp;

  i = 0;
  while (buff[i])
    {
      tmp = sh->alias;
      while (tmp != NULL)
	{
	  if (!(strncmp(&buff[i], tmp->alias, strlen(tmp->alias) + 1)))
	    {
	      if ((buff = replace_word(buff, tmp, &i)))
		return (buff);
	    }
	  tmp = tmp->next;
	}
      i++;
    }
  return (buff);
}
