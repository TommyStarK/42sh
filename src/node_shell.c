/*
** node_shell.c for 42sh in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/final_build
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Tue May 20 22:17:13 2014 chambon emmanuel
** Last update Tue May 20 22:21:09 2014 chambon emmanuel
*/

#include "42.h"

int		node_shell(t_sh *sh)
{
  static int	i = 0;
  i++;
  if (i == 10000000)
    return (-1);
  return (0);
}
