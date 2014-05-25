/*
** purge_str.c for purge_str in /home/amouro_d/truc
**
** Made by Dorian Amouroux
** Login   <amouro_d@epitech.net>
**
** Started on  Mon Mar 31 13:45:52 2014 Dorian Amouroux
** Last update Sun May 25 06:29:25 2014 chambon emmanuel
*/

#include "42.h"

int	is_separator(char letter, char *sep)
{
  int	i;

  i = 0;
  while (sep[i])
    {
      if (letter == sep[i])
	return (1);
      i++;
    }
  return (0);
}

void	purge_end(char *str, char *sep)
{
  int	i;

  i = (int)strlen(str) - 1;
  while (i >= 0 && is_separator(str[i], sep))
    str[i--] = 0;
}

char	*purge_str(char *str, char *sep, int *len)
{
  int	i;

  if (str == NULL)
    return (NULL);
  i = 0;
  while (is_separator(str[0], sep))
    str = &str[1];
  purge_end(str, sep);
  *len = (int)strlen(str);
  while (str[i])
    {
      if (is_separator(str[i], sep))
	str[i] = 0;
      i++;
    }
  return (str);
}
