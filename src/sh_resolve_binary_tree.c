/*
** sh_resolve_binary_tree.c for 42sh in /home/milox_t/Dropbox/42sh
**
** Made by thomas milox
** Login   <milox_t@epitech.net>
**
** Started on  Wed May 14 02:27:09 2014 thomas milox
** Last update Sat May 24 22:51:09 2014 chambon emmanuel
*/

#include "42.h"

int		do_exec_local(t_sh *sh, t_bin *tmp)
{
  int		status;
  pid_t		pid;

  if (access(tmp->cmd[0], R_OK) == -1)
    {
      fprintf(stderr, ACCESS_DENIED, strerror(errno));
      sh->success = 1;
      return (1);
    }
  if ((pid = vfork()) == -1)
    {
      fprintf(stderr, ERR_FORK);
      return (0);
    }
  else if (pid == 0)
    execve(tmp->cmd[0], tmp->cmd, sh->env);
  else
    {
      wait(&status);
      sh->success = get_signal_end_cmd(status);
    }
  return (1);
}

int		do_exec(t_sh *sh, t_bin *tmp, int status)
{
  char		*cmd_to_exec;
  pid_t		pid;

  if ((tmp->cmd[0][0] == '.' && tmp->cmd[0][1] == '/')
      || (tmp->cmd[0][0] == '/'))
    return (do_exec_local(sh, tmp));
  if (!(cmd_to_exec = get_path(sh, tmp, 0)))
    {
      fprintf(stderr, ERR_CMD, tmp->cmd[0]);
      return ((sh->success = 1));
    }
  if ((pid = vfork()) == -1)
    {
      fprintf(stderr, ERR_FORK);
      return (0);
    }
  else if (pid == 0)
    execve(cmd_to_exec, tmp->cmd, sh->env);
  else
    {
      wait(&status);
      sh->success = get_signal_end_cmd(status);
    }
  free(cmd_to_exec);
  return (1);
}

int		dispatch_sep_or_op(t_sh *sh, t_bin *tmp)
{
  if (!(strcmp(tmp->op, ";")))
    {
      resolve_binary_tree(sh, &tmp->l);
      resolve_binary_tree(sh, &tmp->r);
    }
  else if (!(strcmp(tmp->op, "&&")) || !(strcmp(tmp->op, "||")))
    make_separators(sh , tmp);
  else if (!(strcmp(tmp->op, "<")))
    return (make_lredir(sh, tmp));
  else if (!(strcmp(tmp->op, "<<")))
    return (make_d_lredir(sh, tmp));
  else if (!(strcmp(tmp->op, ">")))
    return (make_rredir(sh, tmp));
  else if (!(strcmp(tmp->op, ">>")))
    return (make_d_rredir(sh, tmp));
  else if (!(strcmp(tmp->op, "|")))
    return (make_pipe(sh, tmp));
  return (1);
}

int		resolve_binary_tree(t_sh *sh, t_bin **tree)
{
  int		builtins;
  t_bin		*tmp;

  tmp = *tree;
  if (tmp->cmd)
    {
      if ((builtins = check_builtins(sh, tmp)) == -1)
      	return (0);
      else if (builtins == 0)
	return (1);
      else
	{
	  if (!(do_exec(sh, tmp, 0)))
	    return (0);
	}
    }
  else
    {
      if (!(dispatch_sep_or_op(sh, tmp)))
	return (0);
    }
  return (1);
}
