/*
** alias.c for 42sh in /home/sarda_j/Dropbox/42sh/groupe_milox/sarda_j/
**
** Made by chambon emmanuel
** Login   <sarda_j@epitech.net>
**
** Started on  Mon May 19 21:47:02 2014 chambon emmanuel
** Last update Sun May 25 00:21:07 2014 chambon emmanuel
*/

#include "42.h"

char		*replace_alias(char *line, t_sh *sh)
{
  int		i;
  t_alias	*tmp;
  char		**cmd;
  char		*ret;

  i = 0;
  if (!(cmd = my_str_to_wordtab(line, ' ')))
    return (line);
  tmp = sh->alias;
  while (tmp)
    {
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
  i = 1;
  ret = strdup(cmd[0]);
  while (cmd[i])
    {
      if (!(ret = my_strcat(ret, " "))
	  || !(ret = my_strcat(ret, cmd[i++])))
	return (line);
    }
  free(line);
  free_tab(cmd);
  return (ret);
}

/* char		*replace_word(char *buff, t_alias *tmp, int *i) */
/* { */
/*   int		j; */
/*   char		*new_buff; */

/*   j = *i; */
/*   if (!(new_buff = my_xmalloc(sizeof(char) * strlen(tmp->replace) + strlen(&buff[*i]) + 1))) */
/*     return (NULL); */
/*   my_strncpy(new_buff, buff, *i); */
/*   new_buff[*i] = '\0'; */
/*   strcat(new_buff, tmp->replace); */
/*   printf("new_buff = %s - &buff = <%s>\n", new_buff, &buff[j + strlen(tmp->alias)]); */
/*   strcat(new_buff, &buff[j + strlen(tmp->alias)]); */
/*   *i = *i + (int)strlen(tmp->replace); */
/*   free(buff); */
/*   return (new_buff); */
/* } */

/* char		*replace_alias(char *buff, t_sh *sh) */
/* { */
/*   int		i; */
/*   t_alias	*tmp; */

/*   i = 0; */
/*   while (buff[i]) */
/*     { */
/*       tmp = sh->alias; */
/*       while (tmp != NULL) */
/* 	{ */
/* 	  if (!(strncmp(&buff[i], tmp->alias, strlen(tmp->alias)))) */
/* 	    { */
/* 	      buff = replace_word(buff, tmp, &i); */
/* 	    } */
/* 	  tmp = tmp->next; */
/* 	} */
/*       i++; */
/*     } */
/*   return (buff); */
/* } */
