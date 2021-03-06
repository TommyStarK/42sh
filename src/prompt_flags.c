/*
** prompt_flags.c for 42sh in /home/sarda_j/Dropbox/42sh/groupe_milox/sarda_j/
**
** Made by sarda_j
** Login   <sarda_j@epitech.net>
**
** Started on  Wed May 21 22:13:32 2014 sarda_j
** Last update Sun May 25 15:39:30 2014 sarda_j
*/

#include "42.h"

int		my_varlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\\')
	return (i);
      i++;
    }
  return (0);
}

int		get_color_code(char *color)
{
  if (!(strcmp(color, "grey")))
    return (30);
  else if (!(strcmp(color, "red")))
    return (31);
  else if (!(strcmp(color, "green")))
    return (32);
  else if (!(strcmp(color, "yellow")))
    return (33);
  else if (!(strcmp(color, "blue")))
    return (34);
  else if (!(strcmp(color, "pink")))
    return (35);
  else if (!(strcmp(color, "cyan")))
    return (36);
  else if (!(strcmp(color, "white")))
    return (0);
  else if (!(strcmp(color, "endcolor")))
    return (0);
  return (-1);
}
