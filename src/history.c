/*
** history.c for 42sh in /home/amouro_d/Dropbox/B2/42sh/groupe_milox/amouro_d/src
**
** Made by Dorian Amouroux
** Login   <amouro_d@epitech.net>
**
** Started on  Mon May 19 13:35:43 2014 Dorian Amouroux
** Last update Sun May 25 08:47:09 2014 chambon emmanuel
*/

#include "42.h"

int	history_up(t_editor *editor)
{
  if (editor->current->prev == NULL)
    return (0);
  move_start(editor);
  CAPS("cd");
  editor->current = editor->current->prev;
  my_putstr(editor->current->str);
  my_strcpy(editor->command.str, editor->current->str);
  editor->command.len = (int)strlen(editor->command.str);
  editor->command.pos = editor->command.len;
  return (0);
}

int	history_down(t_editor *editor)
{
  if (editor->current->next == NULL || editor->current->next->str == NULL)
    return (0);
  move_start(editor);
  CAPS("cd");
  editor->current = editor->current->next;
  my_putstr(editor->current->str);
  my_strcpy(editor->command.str, editor->current->str);
  editor->command.len = (int)strlen(editor->command.str);
  editor->command.pos = editor->command.len;
  return (0);
}

t_hist		*get_last(t_hist *list)
{
  t_hist	*last;

  if (list == NULL)
    return (NULL);
  last = list;
  while (last->next != NULL)
    last = last->next;
  return (last);
}

int		add_command_history(t_hist **list, char *str)
{
  t_hist	*last;
  t_hist	*elem;

  if (!(elem = my_malloc(sizeof(t_hist))))
    return (-1);
  elem->str = str;
  elem->next = NULL;
  elem->prev = NULL;
  if ((*list) == NULL)
    *list = elem;
  else
    {
      last = get_last(*list);
      last->next = elem;
      elem->prev = last;
    }
  return (0);
}

void		show_history(t_hist *list)
{
  int		i;
  t_hist	*tmp;

  i = 0;
  tmp = list;
  while (tmp != NULL)
    {
      i++;
      printf("  %d\t%s\n", i, tmp->str);
      tmp = tmp->next;
    }
}
