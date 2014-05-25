/*
** termcaps_code.c for 42.h in /home/tequilol/test/src
**
** Made by Dorian Amouroux
** Login   <tequilol@epitech.net>
**
** Started on  Sun May 25 18:09:55 2014 Dorian Amouroux
** Last update Sun May 25 23:08:24 2014 chambon emmanuel
*/

#include "42.h"

t_termcaps	*list_caps;

void	write_this_code(char *name)
{
  int	i;

  i = 0;
  while (i < 6)
    {
      if (strcmp(name, list_caps[i].name) == 0)
	{
	  my_putstr(list_caps[i].code);
	  return ;
	}
      i++;
    }
}

int	check_list_termcaps(void)
{
  int	i;

  i = 0;
  while (i < 6)
    {
      if (list_caps[i].name == NULL)
	  return (-1);
      i++;
    }
  i = 0;
  while (i < 6)
    {
      if (list_caps[i].code == NULL)
	{
	  fprintf(stderr, NO_TERMCAPS);
	  return (-1);
	}
      i++;
    }
  return (0);
}

int	init_list_caps(void)
{
  list_caps = my_malloc(6 * sizeof(t_termcaps));
  if (list_caps == NULL)
    return (-1);
  list_caps[0].name = my_strdup("cd");
  list_caps[0].code = tgetstr("cd", NULL);
  list_caps[1].name = my_strdup("cl");
  list_caps[1].code = tgetstr("cl", NULL);
  list_caps[2].name = my_strdup("up");
  list_caps[2].code = tgetstr("up", NULL);
  list_caps[3].name = my_strdup("nd");
  list_caps[3].code = tgetstr("nd", NULL);
  list_caps[4].name = my_strdup("sc");
  list_caps[4].code = tgetstr("sc", NULL);
  list_caps[5].name = my_strdup("rc");
  list_caps[5].code = tgetstr("rc", NULL);
  return (check_list_termcaps());
}
