/*
** str_wtab.c for  in /home/milox_t/
**
** Made by thomas milox
** Login   <milox_t@epitech.net>
**
** Started on  Fri Dec  6 09:34:45 2013 thomas milox
** Last update Wed May 21 17:53:13 2014 thomas milox
*/

#include <stdlib.h>
#include "tools.h"

int		word_len(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
	i++;
      else
	return (i);
    }
  return (i);
}

int		nb_words(char *str)
{
  int		i;
  int		flag;
  int		res;

  i = 0;
  flag = 0;
  res = 0;
  while (str[i])
    {
      if ((str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
	  && !flag)
	{
	  res++;
	  flag = 1;
	}
      else if (str[i] == ' ' || str[i] == '\t'|| str[i] == '\n')
	flag = 0;
      i++;
    }
  return (res);
}

void		my_ncpy(char *src, int n, char *dest)
{
  int		i;

  i = 0;
  while (i < n)
    {
      dest[i] = src[i];
      ++i;
    }
  dest[i] = '\0';
}

char		**str_wtab(char *str)
{
  char		**res;
  int		nb_w;
  int		w_len;
  int		i;
  int		j;

  nb_w = nb_words(str);
  if ((res = malloc(sizeof(char *) * (nb_w + 1))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (j < nb_w)
    {
      while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
	i++;
      w_len = word_len(&str[i]);
      if ((res[j] = malloc(w_len + 1)) == NULL)
	return (NULL);
      my_ncpy(&str[i], w_len, res[j++]);
      i += w_len;
    }
  res[j] = NULL;
  return (res);
}
