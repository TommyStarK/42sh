/*
** tools3.c for 42sh in /home/milox_t/Dropbox/42sh/groupe_milox/milox_t
**
** Made by thomas milox
** Login   <milox_t@epitech.net>
**
** Started on  Sat May 17 17:02:07 2014 thomas milox
** Last update Wed May 21 17:46:13 2014 thomas milox
*/

#include "tools.h"

int		my_strcmp(char *s1, char *s2)
{
  int		i;

  i = 0;
  if (!s1 || !s2)
    return (0);
  if (my_strlen(s1) != my_strlen(s2))
    return (0);
  while (s1[i])
    {
      if (s1[i] != s2[i])
	return (0);
      ++i;
    }
  return (1);
}

char		*my_realloc(char *str, int size)
{
  char		*res;
  int		i;

  i = 0;
  if ((res = malloc(size + BUFF_SIZE + 1)) == NULL)
    return (NULL);
  while (i < size)
    res[i] = str[i++];
  free(str);
  return (res);
}

void		new_buff(char buff[], int j, int size)
{
  int		i;

  i = 0;
  while (j < size)
    buff[i++] = buff[j++];
  buff[i] = '\0';
}

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

char		*get_next_line(const int fd)
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
