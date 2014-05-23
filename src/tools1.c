/*
** tools1.c for fonctions utiles in /home/milox_t/Desktop
**
** Made by thomas milox
** Login   <milox_t@epitech.net>
**
** Started on  Fri Dec  6 20:07:28 2013 thomas milox
** Last update Fri May 23 08:40:41 2014 thomas milox
*/

#include "tools.h"

int		my_strlen(char *s)
{
  int		i;

  i = 0;
  if (s == NULL)
    return (0);
  while (s[i])
    i++;
  return (i);
}

int		my_getnbr(char *s)
{
  int		result;
  int		i;

  i = 0;
  result = 0;
  while (s[i])
    result = result * 10 + s[i++] - '0';
  return (result);
}
