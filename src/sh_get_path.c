/*
** sh_get_path_to_exec_cmd.c for 42sh in /home/milox_t/Dropbox/42sh/
**
** Made by thomas milox
** Login   <milox_t@epitech.net>
**
** Started on  Sat May  3 06:12:59 2014 thomas milox
** Last update Fri May 23 21:06:05 2014 chambon emmanuel
*/

#include "42.h"

char		*patch_path_to_execve(t_bin *tmp, int size, char *current_path)
{
  int		x;
  int		y;
  char		*path;

  x = (int)strlen(current_path);
  y = (int)strlen(tmp->cmd[0]);
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
  while (env[i] && strncmp(env[i], variable, strlen(variable)))
    i++;
  if (!env[i])
    {
      fprintf(stderr, MISSING_ENV, (int)strlen(variable), variable);
      return (0);
    }
  else
    return (i);
}

char		*get_path(t_sh *sh, t_bin *tmp, int i)
{
  int		size;
  char		*path;
  char		**path_tab;

  if ((i = check_if_env_variable_exist(sh->env, "PATH=")) == 0)
    return (NULL);
  if ((path_tab = my_str_to_wordtab(&(sh->env[i][5]), ':')) == NULL)
    return (NULL);
  i = -1;
  while (path_tab[++i])
    {
      size = ((int)strlen(path_tab[i]) + (int)strlen(tmp->cmd[0]) + 2);
      if ((path = malloc(sizeof(char) * size)) == NULL)
	return (NULL);
      path = patch_path_to_execve(tmp, size, path_tab[i]);
      if (access(path, F_OK) == 0)
	{
	  free_tab(path_tab);
	  return (path);
	}
      else
	free(path);
    }
  return (NULL);
}
