/*
** gt_next_line.c for 42 in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/PSU_2013_42sh/src
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Fri May 23 21:09:55 2014 chambon emmanuel
** Last update Fri May 23 21:11:02 2014 chambon emmanuel
*/

#include "42.h"

char		*nxt_line(char *res, const int fd, char buff[], t_it *it)
{
  int		flag;

  flag = 1;
  while (flag)
    {
      if ((it->size = read(fd, buff, BUFF_SIZE)) <= 0)
        {
          free(res);
          return (NULL);
        }
      it->j = 0;
      while (it->j < it->size && flag)
        {
          if (buff[it->j] != '\n' && buff[it->j] != '\0')
            res[(it->i)++] = buff[(it->j)++];
          else
            flag = 0;
        }
      if (flag && (res = my_realloc(res, it->i)) == NULL)
        return (NULL);
    }
  ((it->j == it->size || buff[it->j] == '\0') ? buff[0] = '\0' :
   new_buff(buff, it->j + 1 , it->size));
  return (res);
}

char		*gt_next_line(const int fd)
{
  static char	buff[BUFF_SIZE] = "";
  char		*res;
  static t_it	it;

  if ((res = malloc(BUFF_SIZE + 1)) == NULL)
    return (NULL);
  it.i = 0;
  while (buff[it.i])
    {
      if (buff[it.i] == '\n')
        {
          res[it.i++] = '\0';
          new_buff(buff, it.i , it.size);
          return (res);
        }
      res[it.i] = buff[(it.i)++];
    }
  if (buff[it.i] != EOF && (res = my_realloc(res, it.i)) == NULL)
    return (NULL);
  if ((res = nxt_line(res, fd, buff, &it)) == NULL)
    return (NULL);
  res[it.i] = '\0';
  return (res);
}
