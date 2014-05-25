/*
** sh_operators.c for 42sh in /home/milox_t/Dropbox/42sh/groupe_milox/milox_t
**
** Made by thomas milox
** Login   <milox_t@epitech.net>
**
** Started on  Sat May 17 01:14:08 2014 thomas milox
** Last update Sun May 25 07:11:54 2014 thomas milox
*/

#include "42.h"

int			make_rredir(t_sh *sh, t_bin *tmp)
{
  static t_exe		ret;

  if ((ret.stdout = dup(1)) == -1)
    return (0);
  if ((ret.pipefd[0] = open(tmp->r->cmd[0], O_CREAT | O_TRUNC | O_WRONLY,
			    S_IRUSR | S_IWUSR)) == -1)
    return (0);
  if (dup2(ret.pipefd[0], 1) == -1)
    return (0);
  if (!(resolve_binary_tree(sh, &tmp->l)))
    return (0);
  if (close(ret.pipefd[0]) == -1 || dup2(ret.stdout, 1) == -1
      || close(ret.stdout) == -1)
    return (0);
  return (1);
}

int			make_d_rredir(t_sh *sh, t_bin *tmp)
{
  static t_exe		ret;

  if ((ret.stdout = dup(1)) == -1)
    return (0);
  if ((ret.pipefd[0] = open(tmp->r->cmd[0], O_CREAT| O_APPEND | O_WRONLY,
			    S_IRUSR | S_IWUSR)) == -1)
    return (0);
  if (dup2(ret.pipefd[0], 1) == -1)
    return (0);
  if (!(resolve_binary_tree(sh, &tmp->l)))
    return (0);
  close(ret.pipefd[0]);
  if (dup2(ret.stdout, 1) == -1)
    return (0);
  close(ret.stdout);
  return (1);
}

int			make_lredir(t_sh *sh, t_bin *tmp)
{
  static t_exe		ret;

  if ((ret.stdin = dup(0)) == -1)
    return (0);
  if ((ret.pipefd[0] = open(tmp->r->cmd[0], O_RDONLY)) == -1)
    return (0);
  if (dup2(ret.pipefd[0], 0) == -1)
    return (0);
  if (!(resolve_binary_tree(sh, &tmp->l)))
    return (0);
  if (dup2(ret.stdin, 0) == -1)
    return (0);
  close(ret.stdin);
  close(ret.pipefd[0]);
  return (1);
}

int			make_d_lredir(t_sh *sh, t_bin *tmp)
{
  static char		*res=NULL;
  static t_exe		ret;

  if (pipe(ret.pipefd) == -1 || (ret.stdout = dup(1)) == -1 ||
      dup2(ret.pipefd[1], 1) == -1)
      	return (0);
  if (!(res = handle_d_lredir(tmp->r->cmd[0], 0)))
    return (0);
  if (write(ret.pipefd[1], res, strlen(res)) == -1)
    return (0);
  free(res);
  close(ret.pipefd[1]);
  if (dup2(ret.stdout, 1) == -1 || (ret.stdin = dup(0)) == -1
      || dup2(ret.pipefd[0], 0) == -1)
    return (0);
  if (!(resolve_binary_tree(sh, &tmp->l)))
    return (0);
  if (close(ret.pipefd[0]) || dup2(ret.stdout, 1) == -1
      || dup2(ret.stdin, 0) == -1 || close(ret.stdin) == -1)
    return (0);
  close(ret.stdout);
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
  if (!(resolve_binary_tree(sh, &tmp->l)))
    return (0);
  if (dup2(ret.stdout, 1) == -1 || (ret.stdin = dup(0)) == -1
      || dup2(ret.pipefd[0], 0) == -1)
    return (0);
  if (ptr == tmp)
    close(ret.pipefd[0]);
  if (!(resolve_binary_tree(sh, &tmp->r)))
    return (0);
  if (ptr == tmp)
    {
      ptr = NULL;
      if (dup2(ret.stdin, 0) == -1 || close(ret.stdin) == -1
	  || close(ret.stdout) == -1)
  	return (0);
    }
  else
    {
      if (dup2(ret.stdin, 0) == -1 || close(ret.stdin) == -1)
	return (0);
    }
  return (1);
}
