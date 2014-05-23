/*
** node_shell.c for 42sh in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/final_build
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Tue May 20 22:17:13 2014 chambon emmanuel
** Last update Fri May 23 07:24:08 2014 chambon emmanuel
*/

#include "42.h"

int		node_shell(t_sh *sh)
{
  char		buffer[1024];
  int		ret;

  bzero(buffer, 1024);
  my_putstr("PROMPT $> ");
  if (ret = read(0, buffer, 1024) <= 1)
    return (-1);
  buffer[ret - 1] = 0;
  printf("buffer = <%s>\n", buffer);
  if (!(strcmp(buffer, "exit")))
    return (-1);
  epur_str(buffer);
  sh->tree = create_binary_tree(&sh->tree, buffer, my_strlen(buffer));
  print_tree(sh->tree);
  resolve_binary_tree(sh, &sh->tree);
  free_binary_tree(sh->tree);
  return (0);
}
