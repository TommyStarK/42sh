/*
** node_shell.c for 42sh in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/final_build
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Tue May 20 22:17:13 2014 chambon emmanuel
** Last update Sun May 25 23:27:09 2014 chambon emmanuel
*/

#include "42.h"

int		is_ascii(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if ((unsigned char)str[i] > 254 || (unsigned char)str[i] < 1)
	{
	  fprintf(stderr, URANDOM);
	  return (-1);
	}
      i++;
    }
  return (0);
}

int		node_shell(t_editor *editor)
{
  char		*buffer;

  if (!(buffer = read_stdin(editor)))
    return (-1);
  if (is_ascii(buffer))
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
