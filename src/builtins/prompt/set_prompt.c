/*
** prompt.c for 42sh in /home/sarda_j/Dropbox/42sh/groupe_milox/sarda_j/
**
** Made by sarda_j
** Login   <sarda_j@epitech.net>
**
** Started on  Mon May 19 22:00:29 2014 sarda_j
** Last update Thu May 22 14:50:49 2014 chambon emmanuel
*/

#include "42.h"

int		set_prompt(t_sh *sh, char **opt)
{
  char		*prompt;

  if ((prompt = malloc(sizeof(char) * my_strlen(opt[0]) + 1)) == NULL)
    return (-1);
  prompt = my_strncpy_m(opt[0], my_strlen(opt[0]));
  prompt[my_strlen(opt[0])] = '\0';
  if (sh->prompt == NULL)
    sh->prompt = prompt;
  else
    {
      free(sh->prompt);
      sh->prompt = prompt;
    }
  return (0);
}
