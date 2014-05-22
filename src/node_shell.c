/*
** node_shell.c for 42sh in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/final_build
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Tue May 20 22:17:13 2014 chambon emmanuel
** Last update Thu May 22 23:31:25 2014 chambon emmanuel
*/

#include "42.h"

int		node_shell(t_sh *sh)
{
  /* Prompt + read -> dorian */
  char		buff[BUFF_SIZE];

  /* READ TEMPORAIRE #################################### */
  int i = read(0, buff, BUFF_SIZE);
  buff[i - 1] = 0;
  printf("buff = <%s>\n", buff);
  if (!(strcmp(buff, "exit")))
    return (-1);
  /* READ TEMPORAIRE #################################### */
  sh->tree = create_binary_tree(&sh->tree, buff, my_strlen(buff));
  print_tree(sh->tree);
  resolve_binary_tree(sh, &sh->tree);
  free_binary_tree(sh->tree);

  /* execution -> milox */
  /* if (execution == -1) return (-1) */


  return (0);
}
