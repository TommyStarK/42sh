/*
** set_prompt.c for 42 in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/PSU_2013_42sh/src/builtins/prompt
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Sat May 24 00:12:02 2014 chambon emmanuel
** Last update Sun May 25 21:11:57 2014 chambon emmanuel
*/

#include "42.h"

int		set_prompt(t_sh *sh, char **opt, int flag)
{
  char          *prompt;

  if (!(prompt = my_strncpy_m(opt[0], (int)strlen(opt[0]))))
    return (0);
  prompt[(int)strlen(opt[0])] = '\0';
  if (!sh->prompt)
    sh->prompt = prompt;
  else
    {
      free(sh->prompt);
      sh->prompt = prompt;
    }
  if (flag)
    free_tab(opt);
  return (0);
}
