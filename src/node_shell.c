/*
** node_shell.c for 42sh in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/final_build
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Tue May 20 22:17:13 2014 chambon emmanuel
** Last update Sat May 24 00:49:40 2014 chambon emmanuel
*/

#include "42.h"

int		node_shell(t_sh *sh)
{
  char		buffer[1024];
  int		ret;

  bzero(buffer, 1024);
  /* printf("yolo\n"); */
  print_prompt(sh);
  /* printf("yola\n"); */
  if ((ret = read(0, buffer, 1024)) <= 1)
    return (-1);
  buffer[ret - 1] = 0;
  epur_str(buffer);
  sh->tree = create_binary_tree(&sh->tree, buffer, (int)strlen(buffer));
  if (!(resolve_binary_tree(sh, &sh->tree)))
    return (-1);
  free_binary_tree(sh->tree);
  return (0);
}
