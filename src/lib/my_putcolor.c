/*
** my_putcolor.c for 42 in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/PSU_2013_42sh
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sat May 24 00:34:59 2014 chambon emmanuel
** Last update Sat May 24 01:15:45 2014 chambon emmanuel
*/

#include "42.h"

int		my_putchar_color(char c, int color)
{
  printf("\033[1;%d;48m%c\033[0m", color, c);
  fflush(stdout);
  return (1);
}

int		my_putstr_color(char *str, int color)
{
  int		i;

  i = 0;
  while (str[i])
    {
      printf("\033[1;%d;48m%c\033[0m", color, str[i]);
      fflush(stdout);
      i++;
    }
  return (i);
}
