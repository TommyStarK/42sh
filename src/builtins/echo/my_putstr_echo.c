/*
** my_putstr_echo.c for 42 in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/PSU_2013_42sh
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sun May 25 04:03:45 2014 chambon emmanuel
** Last update Sun May 25 04:04:55 2014 chambon emmanuel
*/

#include "42.h"

void		my_putstr_echo(char *str, int flag)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (flag >= 2 && (str[i] == '\\') && str[i + 1])
        {
          if (str[i + 1] == 'a' || str[i + 1] == 'b' || str[i + 1] == 'f')
            my_putchar(str[i + 1] - 90);
          else if (str[i + 1] == 't')
            my_putchar(9);
          else if (str[i + 1] == 'n')
            my_putchar(10);
          else if (str[i + 1] == 'v')
            my_putchar(11);
          else if (str[i + 1] == 'r')
            my_putchar(3);
          else
            my_putchar('\\');
          i++;
        }
      else
        my_putchar(str[i]);
      i++;
    }
}
