/*
** handle.c for 42sh in /home/tequilol/Dropbox/B2/42sh/groupe_milox/amouro_d/src
**
** Made by Dorian Amouroux
** Login   <tequilol@epitech.net>
**
** Started on  Sat May 24 23:12:53 2014 Dorian Amouroux
** Last update Sun May 25 17:17:37 2014 Dorian Amouroux
*/

#include "42.h"

int	clear_the_screen(t_editor *editor)
{
  CAPS("cl");
  editor->len_prompt = print_prompt(&editor->sh, 0);
  my_putstr(editor->command.str);
  editor->command.pos = editor->command.len;
  return (0);
}

int	handle_eot(t_editor *editor)
{
  if (editor->command.len == 0)
    {
      editor->last->prev->next = NULL;
      my_free(editor->last);
      my_putstr("exit\n");
      return (-1);
    }
  else
    return (erase_right(editor));
}

void	handle_winch(int sig_handler)
{
  USELESS(sig_handler);
  /* if (ioctl(0, TIOCGWINSZ, &size_term) == -1) */
  /*   perror("ioctl"); */
}
