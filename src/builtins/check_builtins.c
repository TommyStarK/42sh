/*
** dispatch_builtins.c for 42sh in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/PSU_2013_42sh/src/builtins
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Thu May 22 14:29:14 2014 chambon emmanuel
** Last update Sun May 25 05:37:20 2014 chambon emmanuel
*/

#include "42.h"

int		check_builtins(t_sh *sh, t_bin *tmp)
{
  if (!(strcmp(tmp->cmd[0], "exit")))
    return (-1);
  else if (!(strcmp(tmp->cmd[0], "cd")))
    return (cd(&tmp->cmd[1], sh));
  else if (!(strcmp(tmp->cmd[0], "env")))
    return (my_env(&tmp->cmd[1], sh, 0));
  else if (!(strcmp(tmp->cmd[0], "setenv")))
    return (my_setenv(&tmp->cmd[1], sh));
  else if (!(strcmp(tmp->cmd[0], "unsetenv")))
    return (my_unsetenv(&tmp->cmd[1], sh));
  else if (!(strcmp(tmp->cmd[0], "echo")))
    return (my_echo(&tmp->cmd[1]));
  else if (!(strcmp(tmp->cmd[0], "set-prompt")))
    return (set_prompt(sh, &tmp->cmd[1], 0));
  else if (!(strcmp(tmp->cmd[0], "alias")))
    return (alias(sh, &tmp->cmd[1], 0));
  return (1);
}
