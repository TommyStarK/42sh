/*
** tools2.c for Tools in /home/milox_t/Dropbox
**
** Made by thomas milox
** Login   <milox_t@epitech.net>
**
** Started on  Wed Feb 19 03:04:07 2014 thomas milox
** Last update Fri May 23 08:40:26 2014 thomas milox
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "tools.h"

char    *my_strncpy(char *dest, char *src, int nb)
{
  int   i;

  i = 0;
  while (i < nb)
    {
      if (src[i] == '\0')
        dest[i] = '\0';
      else
        dest[i] = src[i];
      i++;
    }
  return (dest);
}

int     my_strncmp(char *s1, char *s2, int nb)
{
  int   i;

  i = 0;
  if (!s2 || !(*s2))
    return (1);
  while (i < nb)
    {
      if (s1[i] != s2[i])
        return (1);
      i++;
    }
  return (0);
}

char            *epur_str(char *s)
{
    int           i;
    int           j;

    i = -1;
    j = 0;
    if (!s)
      return (0);
    while (s[++i] != '\0')
      {
	if (s[i] != ' ' && s[i] != '\t')
	  {
	    s[j] = s[i];
	    j++;
	    if (s[i + 1] == ' ' || s[i + 1] == '\t')
	      {
		s[j] = ' ';
		j++;
	      }
	  }
      }
    s[j] = '\0';
    if (s[j - 1] == ' ')
      s[j - 1] = '\0';
    return (s);
}

int             my_isnum(char *s)
{
  int           i;

  i = 0;
  if (!s || !(*s))
    return (0);
  while (s[i])
    {
      if (s[i] < '0' || s[i++] > '9')
        return (0);
    }
  return (1);
}

void            xfree(char **name)
{
  int           i;

  i = -1;
  while (name[++i])
    free(name[i]);
  free(name);
}
