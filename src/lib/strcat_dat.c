/*
** strcat_dat.c for 42 in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/PSU_2013_42sh
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sun May 25 01:10:24 2014 chambon emmanuel
** Last update Sun May 25 06:10:01 2014 chambon emmanuel
*/

#include "42.h"

int		tab_len_bytes(char **t)
{
  int		i;
  int		len;

  i = 0;
  len = 0;
  while (t[i])
    {
      len += (int)strlen(t[i]);
      i++;
    }
  return (len);
}

char		*strcat_dat(char **t)
{
  int		size;
  char		*res;
  int		i;

  if (!t || !t[0])
    return (NULL);
  size = tab_len_bytes(t) + tab_len(t, NULL);
  if (!(res = my_xmalloc(size * sizeof(char))))
    return (NULL);
  bzero(res, size);
  i = 0;
  while (t[i])
    {
      strcat(res, t[i]);
      if (t[i + 1])
	strcat(res, " ");
      i++;
    }
  return (res);
}
