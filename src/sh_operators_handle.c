/*
** sh_operators2.c for 42sh in /home/milox_t/Dropbox/42sh/groupe_milox/milox_t
**
** Made by thomas milox
** Login   <milox_t@epitech.net>
**
** Started on  Sat May 17 15:35:55 2014 thomas milox
** Last update Fri May 23 20:52:52 2014 chambon emmanuel
*/

#include "42.h"

t_exe			*set_flux_rredir(t_exe *exe, char **cmd, int flag)
{
  static t_exe			ret;

  if (!flag)
    {
      if ((ret.stdout = dup(1)) == -1)
	return (NULL);
      if ((ret.pipefd[0] = open(cmd[0], O_CREAT| O_TRUNC | O_WRONLY,
				S_IRUSR | S_IWUSR)) == -1)
	return (NULL);
      if (dup2(ret.pipefd[0], 1) == -1)
	return (NULL);
      exe = &ret;
      return (exe);
    }
  else if (flag == 1)
    {
      (void)cmd;
      close(ret.pipefd[0]);
      if (dup2(ret.stdout, 1) == -1)
	return (NULL);
      close(ret.stdout);
      exe = &ret;
      return (exe);
    }
  return (exe);
}

t_exe			*set_flux_d_rredir(t_exe *exe, char **cmd, int flag)
{
  static t_exe			ret;

  if (!flag)
    {
      if ((ret.stdout = dup(1)) == -1)
	return (NULL);
      if ((ret.pipefd[0] = open(cmd[0], O_CREAT| O_APPEND | O_WRONLY,
				S_IRUSR | S_IWUSR)) == -1)
	return (NULL);
      if (dup2(ret.pipefd[0], 1) == -1)
	return (NULL);
      exe = &ret;
      return (exe);
    }
  else if (flag == 1)
    {
      (void)cmd;
      close(ret.pipefd[0]);
      if (dup2(ret.stdout, 1) == -1)
	return (NULL);
      close(ret.stdout);
      exe = &ret;
      return (exe);
    }
  return (exe);
}

t_exe			*set_flux_lredir(t_exe *exe, char **cmd, int flag)
{
  static t_exe		ret;

  if (!flag)
    {
      if ((ret.stdin = dup(0)) == -1)
	return (NULL);
      if ((ret.pipefd[0] = open(cmd[0], O_RDONLY)) == -1)
	return (NULL);
      if (dup2(ret.pipefd[0], 0) == -1)
	return (NULL);
      exe = &ret;
      return (exe);
    }
  else if (flag == 1)
    {
      (void)cmd;
      ret = *exe;
      if (dup2(ret.stdin, 0) == -1)
	return (NULL);
      close(ret.stdin);
      close(ret.pipefd[0]);
      exe = &ret;
      return (exe);
    }
  return (exe);
}

char			*handle_d_lredir(char *match, int fd)
{
  int			x;
  int			y;
  char			*s;
  char			*res;

  if (write(fd, "> ", 2) == -1 || (s = gt_next_line(fd)) == NULL)
    return (NULL);
  res = s;
  while (strcmp(s, match))
    {
      if ((res =  strcat(res, "\n")) == NULL)
	return (NULL);
      if (write(fd, "> ", 2) == -1 || (s = gt_next_line(fd)) == NULL)
	return (NULL);
      if ((res =  strcat(res, s)) == NULL)
	return (NULL);
    }
  x = (int)strlen(s);
  y = (int)strlen(res);
  while (x-- >= 0)
    res[y--] = '\0';
  if ((res =  strcat(res, "\n")) == NULL)
    return (NULL);
  return (res);
}
