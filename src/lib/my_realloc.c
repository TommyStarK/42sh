/*
** my_realloc.c for 42 in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/PSU_2013_42sh/src
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Fri May 23 21:11:34 2014 chambon emmanuel
** Last update Sat May 24 02:00:10 2014 chambon emmanuel
*/

#include "42.h"

void		new_buff(char buff[], int j, int size)
{
  int		i;

  i = 0;
  while (j < size)
    buff[i++] = buff[j++];
  buff[i] = '\0';
}

char            *my_realloc(char *str, int size)
{
  char          *res;
  int           i;

  i = 0;
  if (!(res = my_xmalloc(size + BUFF_SIZE + 1)))
    return (NULL);
  while (i < size)
    res[i] = str[i++];
  free(str);
  return (res);
}
