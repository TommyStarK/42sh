/*
** get_next_line.c for Colle in /home/chambo-e/Dropbox/epitech/Braille
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Wed Apr 30 20:30:20 2014 chambon emmanuel
** Last update Sat May 24 18:33:32 2014 chambon emmanuel
*/

#include "42.h"

int		read_get_next_line(int fd, int *i, int *n, char *buff)
{
  if (*i == *n)
    {
      *i = 0;
      if (!(*n = read(fd, buff, BUFF_SIZE)))
        return (1);
    }
  return (0);
}

int		eol_get_next_line(int fd, int *i, int *n, char *buff)
{
  while (buff[*i] && buff[*i] != '\n')
    {
      (*i)++;
      if (read_get_next_line(fd, i, n, buff))
        return (1);
    }
  return (0);
}

char		*gt_next_line(int fd)
{
  static char	buff[BUFF_SIZE];
  static int	i = 0;
  static int	n = 0;
  int		x;
  char		*str;

  str = NULL;
  x = 0;
  if (read_get_next_line(fd, &i, &n, buff))
    return (0);
  if (!(str = my_xmalloc(sizeof(char) * BUFF_SIZE)))
    return (NULL);
  memset(str, 0, BUFF_SIZE);
  while (buff[i] && buff[i] != '\n' && n < BUFF_SIZE)
    {
      str[x++] = buff[i++];
      if (read_get_next_line(fd, &i, &n, buff))
        return (str);
    }
  if (x == BUFF_SIZE)
    if (eol_get_next_line(fd, &i, &n, buff))
      return (str);
  i++;
  return (str);
}
