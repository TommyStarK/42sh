/*
** node_shell.c for 42sh in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/final_build
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Tue May 20 22:17:13 2014 chambon emmanuel
** Last update Sat May 24 23:22:36 2014 chambon emmanuel
*/

#include "42.h"

int		node_shell(t_sh *sh)
{
  char		*buffer;
  int		ret;

  if (!(buffer = my_xmalloc(1024)))
    return (-1);
  bzero(buffer, 1024);
  print_prompt(sh);
  if ((ret = read(0, buffer, 1024)) <= 1)
    return (-1);
  buffer[ret - 1] = 0;
  epur_str(buffer);
  buffer = replace_alias(buffer, sh);
  printf("bufer = <%s>\n", buffer);
  sh->tree = create_binary_tree(&sh->tree, buffer, (int)strlen(buffer));
  if (!(resolve_binary_tree(sh, &sh->tree)))
    {
      free(buffer);
      free_binary_tree(sh->tree);
      return (-1);
    }
  free_binary_tree(sh->tree);
  free(buffer);
  return (0);
}
