/*
** history2.c for 42sh in /home/tequilol/Dropbox/B2/42sh/groupe_milox/PSU_2013_42sh/src
** 
** Made by Dorian Amouroux
** Login   <tequilol@epitech.net>
** 
** Started on  Sun May 25 08:53:23 2014 Dorian Amouroux
** Last update Sun May 25 20:05:58 2014 Dorian Amouroux
*/

#include "42.h"

void		remove_last(t_editor *editor)
{
  t_hist	*new_last;

  if (editor->history == NULL || editor->last == NULL)
    return ;
  my_free(editor->last->str);
  my_free(editor->last);
  if (editor->last == editor->history)
    {
      editor->history = NULL;
      editor->last = NULL;
    }
  else
    {
      new_last = editor->last->prev;
      new_last->next = NULL;
      my_free(editor->last->str);
      my_free(editor->last);
      editor->last = new_last;
    }
}

char		*get_command_history_index(t_hist *list, int nb)
{
  int		i;
  t_hist	*tmp;

  i = 1;
  tmp = list;
  while (tmp != NULL)
    {
      if (i == nb)
	return (tmp->str);
      tmp = tmp->next;
      i++;
    }
  fprintf(stderr, "42sh: event not found: %d\n", nb);
  return (NULL);
}

int	command_history(t_editor *editor)
{
  int	nb;
  char	*command;

  if (editor->command.str[0] == '!')
    {
      if (editor->command.str[1] == '!')
	nb = -1;
      else
	nb = my_getnbr(&editor->command.str[1]);
      if (nb < 0)
	nb = history_length(editor->history) + nb;
      if (nb < 0)
	nb = 0;
      command = get_command_history_index(editor->history, nb);
      if (command != NULL)
	{
	  my_strcpy(editor->command.str, command);
	  return (0);
	}
      else
	return (-1);
    }
  return (0);
}

char    *get_path_home_history(t_sh *sh)
{
  char  *new_path;
  char  *home;
  int   size;

  if ((home = get_item(sh, "HOME=")) == NULL)
    return (NULL);
  size = strlen(home) + strlen("/.42sh_history");
  if ((new_path = my_malloc(size + 1)) == NULL)
    return (NULL);
  strcpy(new_path, home);
  strcat(new_path, "/.42sh_history");
  return (new_path);
}
