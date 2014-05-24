/*
** sh_operators2.c for 42sh in /home/milox_t/Dropbox/42sh/groupe_milox/milox_t
**
** Made by thomas milox
** Login   <milox_t@epitech.net>
**
** Started on  Sat May 17 15:35:55 2014 thomas milox
** Last update Sat May 24 09:31:57 2014 thomas milox
*/

#include "42.h"

void                    make_separators(t_sh *sh, t_bin *tmp)
{
  if (!(strcmp(tmp->op, "&&")))
    {
      resolve_binary_tree(sh, &tmp->l);
      if (!(sh->success))
	resolve_binary_tree(sh, &tmp->r);
    }
  else if (!(strcmp(tmp->op, "||")))
    {
      resolve_binary_tree(sh, &tmp->l);
      if (sh->success > 0)
	resolve_binary_tree(sh, &tmp->r);
    }
}

char			*handle_d_lredir(char *match, int fd)
{
  int			x;
  int			y;
  char			*s;
  char			*res;

  if (write(fd, "> ", 2) == -1 || !(s = gt_next_line(fd)))
    return (NULL);
  res = s;
  while (strcmp(s, match))
    {
      if (!(res = strcat(res, "\n")))
	return (NULL);
      if (write(fd, "> ", 2) == -1 || !(s = gt_next_line(fd)))
	return (NULL);
      if (!(res =  strcat(res, s)))
	return (NULL);
    }
  x = (int)strlen(s);
  y = (int)strlen(res);
  while (x-- >= 0)
    res[y--] = '\0';
  if (!(res =  strcat(res, "\n")))
    return (NULL);
  return (res);
}
