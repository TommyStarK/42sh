/*
** main.c for 42sh in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/final_build
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Tue May 20 22:01:26 2014 chambon emmanuel
** Last update Fri May 23 06:01:06 2014 chambon emmanuel
*/

#include "42.h"

int		main(int __attribute__((unused))ac, char __attribute__((unused))**av, char **env)
{
  t_sh		sh;

  if (!(sh.env = get_env(env)))
    return (-1);
  sh.alias = NULL;
  sh.prompt = NULL;
  sh.last_return = 0;
  sh.pid_pgr = getpid();
  /* conf_read(&sh); */
  printf("GROOOOSSSS REAADADADDADADAD\n");
  sleep(2);
  /* setup du fichier de conf */
  while (node_shell(&sh) != -1);
  free_sh(&sh);
  return (0);
}
