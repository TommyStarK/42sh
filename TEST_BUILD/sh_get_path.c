/*
** sh_get_path_to_exec_cmd.c for 42sh in /home/milox_t/Dropbox/42sh/
**
** Made by thomas milox
** Login   <milox_t@epitech.net>
**
** Started on  Sat May  3 06:12:59 2014 thomas milox
** Last update Thu May 22 22:47:54 2014 thomas milox
*/

#include "tommy.h"

char		*patch_path_to_execve(t_bin *tmp, int size, char *current_path)
{
  int		x;
  int		y;
  char		*path;

  x = my_strlen(current_path);
  y = my_strlen(tmp->cmd[0]);
  if ((path = malloc(sizeof(char) * size)) == NULL)
    return (NULL);
  my_strncpy(path, current_path, x);
  path[x] = '/';
  my_strncpy(&path[x + 1], tmp->cmd[0], y);
  path[x + y + 1] = '\0';
  return (path);
}

int		check_if_env_variable_exist(char **env, char *variable)
{
  int		i;

  i = 0;
  if (!env || !(*env))
    return (0);
  while (env[i] && my_strncmp(env[i], variable, my_strlen(variable)) != 0)
    i++;
  if (!env[i])
    {
      printf("Shell: '%s': variable not set in 'ENV'.\n", variable);
      return (0);
    }
  else
    return (i);
}

char		*get_path(t_sh *sh, t_bin *tmp)
{
  int		i;
  int		size;
  char		*path;
  char		**path_tab;

  i = 0;
  if ((i = check_if_env_variable_exist(sh->env, "PATH=")) == 0)
    return (NULL);
  if ((path_tab = str_to_tab(&(sh->env[i][5]), ':')) == NULL)
    return (NULL);
  i = -1;
  while (path_tab[++i])
    {
      size = (my_strlen(path_tab[i]) + my_strlen(tmp->cmd[0]) + 2);
      if ((path = malloc(sizeof(char) * size)) == NULL)
	return (NULL);
      path = patch_path_to_execve(tmp, size, path_tab[i]);
      if (access(path, F_OK) == 0)
	{
	  xfree(path_tab);
	  return (path);
	}
      else
	free(path);
    }
  return (NULL);
}
