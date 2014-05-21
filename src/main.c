/*
** main.c for 42sh in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/final_build
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Tue May 20 22:01:26 2014 chambon emmanuel
** Last update Tue May 20 22:20:00 2014 chambon emmanuel
*/

#include "42.h"

int		main(int __attribute__((unused))ac, char __attribute__((unused))**av, char **env)
{
  t_sh		sh;

  if (!(sh.env = get_env(env)))
    return (-1);
  while (node_shell(&sh) != -1);
  free_sh(&sh);
  return (0);
}
