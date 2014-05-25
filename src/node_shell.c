/*
** node_shell.c for 42sh in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/final_build
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Tue May 20 22:17:13 2014 chambon emmanuel
** Last update Sun May 25 21:37:05 2014 chambon emmanuel
*/

#include "42.h"

int		node_shell(t_editor *editor)
{
  char		*buffer;

  if (!(buffer = read_stdin(editor)))
    return (-1);
  buffer = replace_alias(buffer, &editor->sh, 0, NULL);
  editor->sh.tree = create_binary_tree(&editor->sh.tree,
				       buffer, (int)strlen(buffer));
  editor->sh.history = editor->history;
  if (!(resolve_binary_tree(&editor->sh, &editor->sh.tree)))
    {
      free_binary_tree(editor->sh.tree);
      free(buffer);
      return (-1);
    }
  free(buffer);
  free_binary_tree(editor->sh.tree);
  return (0);
}
