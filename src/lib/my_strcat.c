/*
** my_strcat.c for my_strcat in /home/chambo_e/rendu/Piscine-C-Jour_07/Piscine-C-lib/my
**
** Made by emmanuel chambon
** Login   <chambo_e@epitech.net>
**
** Started on  Wed Oct  9 22:18:27 2013 emmanuel chambon
** Last update Sun May 25 01:58:56 2014 chambon emmanuel
*/

#include "42.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;
  char	*ret;
  int	inc;

  inc = 0;
  i = strlen(src);
  j = strlen(dest);
  if (!(ret = my_xmalloc((i + j + 1) * sizeof(char))))
    return (NULL);
  ret[i + j] = '\0';
  while (dest[inc])
    {
      ret[inc] = dest[inc];
      inc++;
    }
  while (*src)
    {
      ret[inc] = *src;
      src++;
      inc++;
    }
  return (ret);
}
