/*
** my_strdup.c for my_strdup in /home/amouro_d/rendu/Piscine-C-Jour_08
**
** Made by dorian amouroux
** Login   <amouro_d@epitech.net>
**
** Started on  Thu Oct 10 02:33:26 2013 dorian amouroux
** Last update Sun May 25 06:31:30 2014 chambon emmanuel
*/

#include "42.h"

char	*my_strdup(char *src)
{
  int	src_len;
  char	*retour;
  int	i;

  src_len = (int)strlen(src);
  if (!(retour = my_malloc(src_len + 1)))
    return (NULL);
  retour[src_len] = 0;
  i = 0;
  while (i < src_len)
    {
      retour[i] = src[i];
      i++;
    }
  return (retour);
}
