/*
** sh_resolve_binary_tree.c for 42sh in /home/milox_t/Dropbox/42sh
**
** Made by thomas milox
** Login   <milox_t@epitech.net>
**
** Started on  Wed May 14 02:27:09 2014 thomas milox
** Last update Fri May 23 06:20:59 2014 chambon emmanuel
*/

#include "42.h"

int		do_exec_local(t_sh *sh, t_bin *tmp)
{
  int		status;
  pid_t		pid;

  /* if (access(tmp->cmd[0], F_OK) == -1) */
  if (open(tmp->cmd[0], O_RDONLY) == -1);
    {
      printf("sa chie\n");
      /* fprintf(stderr, "access : [%s]\n", strerror(errno)); */
      return (1);
    }
  if ((pid = vfork()) == -1)
    {
     printf(ERR_FORK);
     return (0);
   }
  else if (pid == 0)
    execve(tmp->cmd[0], tmp->cmd, sh->env);
  else
    {
      wait(&status);
      signal_seg(status);
    }
  return (1);
}

int		do_exec(t_sh *sh, t_bin *tmp)
{
  int		status;
  char		*cmd_to_exec;
  pid_t		pid;

  printf("4\n");
  usleep(500000);
  if ((tmp->cmd[0][0] == '.' && tmp->cmd[0][1] == '/')
      || (tmp->cmd[0][0] == '/'))
    return (do_exec_local(sh, tmp));
  if ((cmd_to_exec = get_path(sh, tmp)) == NULL)
    {
      printf(ERR_CMD, tmp->cmd[0]);
      return (1);
    }
  printf("[%s]\n", cmd_to_exec);
  usleep(500000);
  if ((pid = vfork()) == -1)
    {
     printf(ERR_FORK);
     return (0);
   }
  else if (pid == 0)
   execve(cmd_to_exec, tmp->cmd, sh->env);
  else
    {
      printf("DANS LE PERE\n");
      usleep(500000);
      wait(&status);
      signal_seg(status);
    }
  return (1);
}

int		dispatch_sep_or_op(t_sh *sh, t_bin *tmp)
{
  if (my_strcmp(tmp->op, "<") == 1)
    return (make_lredir(sh, tmp));
  else if (my_strcmp(tmp->op, "<<") == 1)
    return (make_d_lredir(sh, tmp));
  else if (my_strcmp(tmp->op, ">") == 1)
    return (make_rredir(sh, tmp));
  else if (my_strcmp(tmp->op, ">>") == 1)
    return (make_d_rredir(sh, tmp));
  else if (my_strcmp(tmp->op, "|") == 1)
    return (make_pipe(sh, tmp));
  else if (my_strcmp(tmp->op, ";") == 1)
    {
      resolve_binary_tree(sh, &tmp->l);
      resolve_binary_tree(sh, &tmp->r);
    }
  return (1);
}

int		resolve_binary_tree(t_sh *sh, t_bin **tree)
{
  t_bin		*tmp;

  tmp = *tree;
  printf("1\n");
  usleep(500000);
  if (tmp->cmd)
    {
      /* if (check_builtins() == 0) */
      /* 	return (0); */
      printf("2\n");
      usleep(500000);
      if (do_exec(sh, tmp) == 0)
	return (0);
    }
  else
    {
      printf("3\n");
      usleep(500000);
      if (dispatch_sep_or_op(sh, tmp) == 0)
	return (0);
    }
  return (1);
}
