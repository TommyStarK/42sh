/*
** sh_operators.c for 42sh in /home/milox_t/Dropbox/42sh/groupe_milox/milox_t
**
** Made by thomas milox
** Login   <milox_t@epitech.net>
**
** Started on  Sat May 17 01:14:08 2014 thomas milox
** Last update Fri May 23 06:22:19 2014 thomas milox
*/

#include "42.h"

/* int			make_rredir(t_sh *sh, t_bin *tmp) */
/* { */
/*   printf("7\n"); */
/*   usleep(500000); */
/*   if ((sh->exe = set_flux_rredir(sh->exe, tmp->r->cmd, 0)) == NULL) */
/*     return (0); */
/*   printf("8\n"); */
/*   usleep(500000); */
/*   if (resolve_binary_tree(sh, &tmp->l) == 0) */
/*     return (0); */
/*   printf("9\n"); */
/*   usleep(500000); */
/*   if ((sh->exe = set_flux_rredir(sh->exe, tmp->r->cmd, 1)) == NULL) */
/*     return (0); */
/*   printf("10\n"); */
/*   usleep(500000); */
/*   return (1); */
/* } */

int			make_rredir(t_sh *sh, t_bin *tmp)
{
  static t_exe		ret;

  printf("7\n");
  usleep(500000);
  if ((ret.stdout = dup(1)) == -1)
    {
      printf("return 1\n");
      return (0);
    }
  if ((ret.pipefd[0] = open(tmp->r->cmd[0], O_CREAT| O_TRUNC | O_WRONLY,
				S_IRUSR | S_IWUSR)) == -1)
    {
      printf("return 2\n");
      return (0);
    }
  if (dup2(ret.pipefd[0], 1) == -1)
    {
      printf("return 3\n");
      return (0);
	}
  if (resolve_binary_tree(sh, &tmp->l) == 0)
    return (0);
  close(ret.pipefd[0]);
  if (dup2(ret.stdout, 1) == -1)
    return (0);
  close(ret.stdout);
  printf("10\n");
  usleep(500000);
  return (1);
}

int			make_d_rredir(t_sh *sh, t_bin *tmp)
{
  printf("11\n");
  usleep(500000);
  if ((sh->exe = set_flux_d_rredir(sh->exe, tmp->r->cmd, 0)) == NULL)
    return (0);
  printf("12\n");
  usleep(500000);
  if (resolve_binary_tree(sh, &tmp->l) == 0)
    return (0);
  printf("13\n");
  usleep(500000);
  if ((sh->exe = set_flux_d_rredir(sh->exe, tmp->r->cmd, 1)) == NULL)
    return (0);
  printf("14\n");
  usleep(500000);
  return (1);
}

int			make_lredir(t_sh *sh, t_bin *tmp)
{
  printf("15\n");
  usleep(500000);
  if ((sh->exe = set_flux_lredir(sh->exe, tmp->r->cmd, 0)) == NULL)
    return (0);
  printf("16\n");
  usleep(500000);
  if (resolve_binary_tree(sh, &tmp->l) == 0)
    return (0);
  printf("17\n");
  usleep(500000);
  if ((sh->exe = set_flux_lredir(sh->exe, tmp->r->cmd, 1)) == NULL)
    return (0);
  printf("18\n");
  usleep(500000);
  return (1);
}

int			make_d_lredir(t_sh *sh, t_bin *tmp)
{
  static char		*res=NULL;
  static t_exe		ret;

  printf("19\n");
  usleep(500000);
  if (pipe(ret.pipefd) == -1 || (ret.stdout = dup(1)) == -1 ||
      dup2(ret.pipefd[1], 1) == -1)
      	return (0);
  if ((res = handle_d_lredir(tmp->r->cmd[0], 0)) == NULL)
    return (0);
  printf("res << [%s]\n", res);
  usleep(500000);
  if (write(ret.pipefd[1], res, my_strlen(res)) == -1)
    return (0);
  free(res);
  close(ret.pipefd[1]);
  if (dup2(ret.stdout, 1) == -1 || (ret.stdin = dup(0)) == -1
      || dup2(ret.pipefd[0], 0) == -1)
    return (0);
  if (resolve_binary_tree(sh, &tmp->l) == 0)
    return (0);
  printf("20\n");
  usleep(500000);
  if (close(ret.pipefd[0]) || dup2(ret.stdout, 1) == -1
      || close(ret.stdout))
    return (0);
  printf("21\n");
  usleep(500000);
  return (1);
}

int			make_pipe(t_sh *sh, t_bin *tmp)
{
  static t_bin		*ptr=NULL;
  static t_exe		ret;

  printf("22\n");
  usleep(500000);
  if (!ptr)
    {
      printf("23\n");
      usleep(500000);
      ptr = tmp;
      printf("24\n");
      usleep(500000);
      if (pipe(ret.pipefd) == -1 || (ret.stdout = dup(1)) == -1 ||
	  dup2(ret.pipefd[1], 1) == -1 || close(ret.pipefd[1]))
      	return (0);
    }
  printf("25\n");
  usleep(500000);
  if (resolve_binary_tree(sh, &tmp->l) == 0)
    return (0);
  printf("26\n");
  usleep(500000);
  if (dup2(ret.stdout, 1) == -1 || (ret.stdin = dup(0)) == -1
      || dup2(ret.pipefd[0], 0) == -1)
    return (0);
  if (ptr == tmp)
    close(ret.pipefd[0]);
  if (resolve_binary_tree(sh, &tmp->r) == 0)
    return (0);
  printf("27\n");
  usleep(500000);
  if (ptr == tmp)
    {
      printf("ptr pipe [%p]\n", ptr);
      usleep(500000);
      ptr = NULL;
      if (dup2(ret.stdin, 0) == -1 || close(ret.stdin))
  	return (0);
    }
  printf("28\n");
  usleep(500000);
  return (1);
}
