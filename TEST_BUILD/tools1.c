/*
** tools1.c for fonctions utiles in /home/milox_t/Desktop
**
** Made by thomas milox
** Login   <milox_t@epitech.net>
**
** Started on  Fri Dec  6 20:07:28 2013 thomas milox
** Last update Sat May 17 17:48:20 2014 thomas milox
*/

#include "tools.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putchar_error(char c)
{
  write(2, &c, 1);
}

void		my_puterror(char *s)
{
  int		i;

  i = 0;
  while (s[i])
    my_putchar_error(s[i++]);
  exit(EXIT_FAILURE);
}

int		my_strlen(char *s)
{
  int		i;

  i = 0;
  if (s == NULL)
    my_puterror("Error: string in paramater strlen is NULL.\n");
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
