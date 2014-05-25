/*
** move.c for 42sh in /home/amouro_d/Dropbox/B2/42sh/groupe_milox/amouro_d/src
**
** Made by Dorian Amouroux
** Login   <amouro_d@epitech.net>
**
** Started on  Fri May 16 12:40:38 2014 Dorian Amouroux
** Last update Sun May 25 18:48:37 2014 Dorian Amouroux
*/

#include "42.h"

int	move_left(t_editor *editor)
{
  int	i;
  int	modulo;

  if (editor->command.pos <= 0)
    return (0);
  modulo = (editor->len_prompt + editor->command.pos) % size_term.ws_col;
  if (modulo == 0)
    {
      i = size_term.ws_col;
      CAPS("up");
      while (i)
	{
	  CAPS("nd");
	  i--;
	}
    }
  else
    my_putchar('\b');
  if (editor->command.pos > 0)
    editor->command.pos--;
  return (0);
}

int	move_right(t_editor *editor)
{
  int	modulo;

  if (editor->command.pos >= editor->command.len)
    return (0);
  modulo = (editor->len_prompt + editor->command.pos) % size_term.ws_col;
  if (modulo == (size_term.ws_col - 1))
    my_putchar('\n');
  else
    CAPS("nd");
  editor->command.pos++;
  return (0);
}

int	move_start(t_editor *editor)
{
  while (editor->command.pos)
    move_left(editor);
  return (0);
}

int	move_end(t_editor *editor)
{
  while (editor->command.pos < editor->command.len)
    move_right(editor);
  return (0);
}
