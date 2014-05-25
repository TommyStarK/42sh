/*
** read_stdin.c for 42sh in /home/amouro_d/Dropbox/42sh/src
**
** Made by Dorian Amouroux
** Login   <amouro_d@epitech.net>
**
** Started on  Fri May  9 14:06:40 2014 Dorian Amouroux
** Last update Sun May 25 20:55:15 2014 Dorian Amouroux
*/

#include "42.h"

static t_action	action_tab[] =
  {
    {ENTER, &end_of_line},
    {LEFT, &move_left},
    {RIGHT, &move_right},
    {BACKSPACE, &erase_left},
    {DELETE, &erase_right},
    {CTRL_A, &move_start},
    {HOME, &move_start},
    {CTRL_E, &move_end},
    {END, &move_end},
    {UP, &history_up},
    {DOWN, &history_down},
    {CTRL_L, &clear_the_screen},
    {CTRL_C, &handle_ctrlc},
    {0, 0}
  };

int		action(t_editor *editor, union u_buffer buff)
{
  int		i;
  static char	*paste = NULL;

  i = 0;
  if (buff.tab_value[0] >= 32 && buff.tab_value[0] <= 126)
    return (insert_letter(&editor->command, buff));
  else if (buff.int_value == CTRL_K)
    return (cut_line(&editor->command, &paste));
  else if (buff.int_value == CTRL_Y)
    return (paste_line(&editor->command, &paste));
  while (action_tab[i].keycode != 0)
    {
      if (buff.int_value == action_tab[i].keycode)
	return (action_tab[i].function(editor));
      i++;
    }
  return (0);
}

void	init_command(t_str *command)
{
  command->str[0] = 0;
  command->str[1] = 0;
  command->len = 0;
  command->pos = 0;
}

char	*no_termcaps_read(void)
{
  char	buffer[1024];
  int	ret;

  if ((ret = read(0, buffer, 1023)) < 1)
    return (strdup("exit"));
  buffer[ret - 1] = 0;
  return (strdup(buffer));
}

char		*format_stdin(t_editor *editor)
{
  if (editor != NULL &&
      editor->last->prev != NULL &&
      editor->last->prev->str != NULL &&
      !(strcmp(editor->command.str, editor->last->prev->str)))
    remove_last(editor);
  else
    {
      my_free(editor->last->str);
      editor->last->str = my_strdup(editor->command.str);
    }
  if (unset_editor(editor) == -1)
    return (NULL);
  else
    return (strdup(editor->last->str));
}

char			*read_stdin(t_editor *editor)
{
  union u_buffer	buffer;
  int		ret;

  editor->len_prompt = print_prompt(&editor->sh, 0);
  if (editor->mode == 1)
    return (no_termcaps_read());
  if (set_editor(editor) == -1)
    return (NULL);
  init_command(&editor->command);
  buffer.int_value = 0;
  if (add_command_history(&editor->history, "") == -1)
    return (NULL);
  editor->last = get_last(editor->history);
  editor->current = editor->last;
  while (read(0, &buffer, 4) > 0)
    {
      if (buffer.int_value == 4 && handle_eot(editor) == -1)
	return (strdup("exit"));
      else if ((ret = action(editor, buffer)) == -1)
	return (format_stdin(editor));
      else if (ret == -2)
	return (NULL);
      buffer.int_value = 0;
    }
  return (NULL);
}
