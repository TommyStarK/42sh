/*
** str_to_tab.c for STR_TO_WORD_TAB in /home/milox_t/Dropbox/
**
** Made by thomas milox
** Login   <milox_t@epitech.net>
**
** Started on  Fri Apr 18 11:12:50 2014 thomas milox
** Last update Mon May 19 23:45:49 2014 thomas milox
*/

#include "tools.h"

#define ERR_MALLOC "Error: 'malloc' syscall failed.\n"

int		word_nbr(char *s, char separator)
{
  int		i;
  int		word_nbr;

  i = 0;
  word_nbr = 0;
  while (s[++i] == separator);
  while (s[i])
    {
      if (s[i] == separator && s[i + 1] != separator)
	word_nbr++;
      i++;
    }
  return (word_nbr + 1);
}

void		make_space(int *i, int *j, int *k)
{
  *i = 0;
  *j = 0;
  *k = 0;
}

char		**str_to_tab(char *s, char separator)
{
  int		i;
  int		j;
  int		k;
  int		word;
  char		**res;

  make_space(&i, &j, &k);
  word = word_nbr(s, separator);
  if ((res = malloc(sizeof(char *) * (word + 1))) == NULL)
    my_puterror(ERR_MALLOC);
  k = j;
  while ((i < word) && (s[j] != '\0'))
    {
      while (s[k++] != separator);
      if ((res[i] = malloc(sizeof(char) * (k - j))) == NULL)
	my_puterror(ERR_MALLOC);
      my_strncpy(res[i], &s[j], (k - j - 1));
      res[i][(k - j - 1)] = '\0';
      j = k;
      i++;
    }
  res[word] = NULL;
  return (res);
}
