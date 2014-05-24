/*
** my_strncpy.c for my_strncpy in /home/sarda_j/Dropbox/42sh/groupe_milox/
**
** Made by sarda_j
** Login   <sarda_j@epitech.net>
**
** Started on  Wed May 21 21:19:32 2014 sarda_j
** Last update Sat May 24 01:59:46 2014 chambon emmanuel
*/

#include "42.h"

char		*my_strncpy_m(char *s, int size)
{
  char		*res;
  int		i;

  if (!(res = my_xmalloc(sizeof(char) * size + 1)))
    return (NULL);
  i = 0;
  while (i < size)
    {
      res[i] = s[i];
      ++i;
    }
  res[i] = '\0';
  return (res);
}
