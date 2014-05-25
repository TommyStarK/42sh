/*
** cut_paste.c for 42sh in /home/tequilol/Dropbox/B2/42sh/groupe_milox/amouro_d/src
**
** Made by Dorian Amouroux
** Login   <tequilol@epitech.net>
**
** Started on  Sat May 24 05:33:00 2014 Dorian Amouroux
** Last update Sun May 25 08:45:47 2014 chambon emmanuel
*/

#include "42.h"

int	cut_line(t_str *current, char **buffer)
{
  if (current->str[current->pos] == 0)
    return (0);
  if (*buffer != NULL)
    my_free(*buffer);
  if (!(*buffer = my_strdup(&current->str[current->pos])))
    return (-1);
  CAPS("cd");
  current->str[current->pos] = 0;
  current->len -= (int)strlen(*buffer);
  return (0);
}

int			paste_line(t_str *current, char **buffer)
{
  int			i;
  union	u_buffer	buff;

  if (*buffer == NULL)
    return (0);
  i = 0;
  while ((*buffer)[i])
    {
      buff.int_value = (*buffer)[i];
      if (insert_letter(current, buff) == 2)
	return (-1);
      i++;
    }
  return (0);
}
