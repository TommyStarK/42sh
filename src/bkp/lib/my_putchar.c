/*
** my_putchar.c for 42sh in /home/chambo_e/Dropbox/42sh/groupe_milox/chambo_e
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Tue Mar 25 13:33:18 2014 chambon emmanuel
** Last update Tue Mar 25 13:33:50 2014 chambon emmanuel
*/

#include <unistd.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}
