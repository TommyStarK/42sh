/*
** sh_operators.c for 42sh in /home/milox_t/Dropbox/42sh/groupe_milox/milox_t
**
** Made by thomas milox
** Login   <milox_t@epitech.net>
**
** Started on  Sat May 17 01:14:08 2014 thomas milox
** Last update Fri May 23 09:56:29 2014 thomas milox
*/

#include "42.h"

int			make_rredir(t_sh *sh, t_bin *tmp)
{
  if ((sh->exe = set_flux_rredir(sh->exe, tmp->r->cmd, 0)) == NULL)
    return (0);
  if (resolve_binary_tree(sh, &tmp->l) == 0)
    return (0);
  if ((sh->exe = set_flux_rredir(sh->exe, tmp->r->cmd, 1)) == NULL)
    return (0);
  return (1);
}

int			make_d_rredir(t_sh *sh, t_bin *tmp)
{
  if ((sh->exe = set_flux_d_rredir(sh->exe, tmp->r->cmd, 0)) == NULL)
    return (0);
  if (resolve_binary_tree(sh, &tmp->l) == 0)
    return (0);
  if ((sh->exe = set_flux_d_rredir(sh->exe, tmp->r->cmd, 1)) == NULL)
    return (0);
  return (1);
}

int			make_lredir(t_sh *sh, t_bin *tmp)
{
  if ((sh->exe = set_flux_lredir(sh->exe, tmp->r->cmd, 0)) == NULL)
    return (0);
  if (resolve_binary_tree(sh, &tmp->l) == 0)
    return (0);
  if ((sh->exe = set_flux_lredir(sh->exe, tmp->r->cmd, 1)) == NULL)
    return (0);
  return (1);
}

int			make_d_lredir(t_sh *sh, t_bin *tmp)
{
  static char		*res=NULL;
  static t_exe		ret;

  if (pipe(ret.pipefd) == -1 || (ret.stdout = dup(1)) == -1 ||
      dup2(ret.pipefd[1], 1) == -1)
      	return (0);
  if ((res = handle_d_lredir(tmp->r->cmd[0], 0)) == NULL)
    return (0);
  if (write(ret.pipefd[1], res, my_strlen(res)) == -1)
    return (0);
  free(res);
  close(ret.pipefd[1]);
  if (dup2(ret.stdout, 1) == -1 || (ret.stdin = dup(0)) == -1
      || dup2(ret.pipefd[0], 0) == -1)
    return (0);
  if (resolve_binary_tree(sh, &tmp->l) == 0)
    return (0);
  if (close(ret.pipefd[0]) || dup2(ret.stdout, 1) == -1
      || dup2(ret.stdin, 0) == -1)
    return (0);
  return (1);
}

int			make_pipe(t_sh *sh, t_bin *tmp)
{
  static t_bin		*ptr=NULL;
  static t_exe		ret;

  if (!ptr)
    {
      ptr = tmp;
      if (pipe(ret.pipefd) == -1 || (ret.stdout = dup(1)) == -1 ||
	  dup2(ret.pipefd[1], 1) == -1 || close(ret.pipefd[1]))
      	return (0);
    }
  if (resolve_binary_tree(sh, &tmp->l) == 0)
    return (0);
  if (dup2(ret.stdout, 1) == -1 || (ret.stdin = dup(0)) == -1
      || dup2(ret.pipefd[0], 0) == -1)
    return (0);
  if (ptr == tmp)
    close(ret.pipefd[0]);
  if (resolve_binary_tree(sh, &tmp->r) == 0)
    return (0);
  if (ptr == tmp)
    {
      ptr = NULL;
      if (dup2(ret.stdin, 0) == -1 || close(ret.stdin))
  	return (0);
    }
  return (1);
}
