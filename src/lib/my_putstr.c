/*
** my_putstr.c for 42sh in /home/chambo_e/Dropbox/42sh/groupe_milox/chambo_e
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Tue Mar 25 13:33:58 2014 chambon emmanuel
** Last update Wed May 14 15:59:53 2014 chambon emmanuel
*/

void		my_putchar(char);

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}
