/*
** wordtab.c for wordtab in /home/amouro_d/truc
**
** Made by Dorian Amouroux
** Login   <amouro_d@epitech.net>
**
** Started on  Mon Mar 31 13:44:51 2014 Dorian Amouroux
** Last update Sun May 25 08:45:26 2014 chambon emmanuel
*/

#include "42.h"

int	count_word(char *str, int len)
{
  int	i;
  int	nb_word;

  i = 0;
  nb_word = 0;
  while (i < len)
    {
      while (str[i] && i < len)
	i++;
      nb_word++;
      while (str[i] == 0 && i < len)
	i++;
    }
  return (nb_word);
}

char	*get_next_word(char *str, int pos, int len)
{
  int	i;

  i = 0;
  while (pos)
    {
      while (str[i] && i < len)
	i++;
      while (str[i] == 0 && i < len)
	i++;
      pos--;
    }
  return (&str[i]);
}

char	**wordtab(char *str, char *sep)
{
  char	**big_one;
  int	len;
  int	size;
  int	i;

  str = purge_str(str, sep, &len);
  size = count_word(str, len);
  if (!(big_one = my_malloc((size + 1) * sizeof(char *))))
    return (NULL);
  big_one[size] = NULL;
  i = 0;
  while (i < size)
    {
      if (!(big_one[i] = my_strdup(get_next_word(str, i, len))))
	return (NULL);
      i++;
    }
  return (big_one);
}
