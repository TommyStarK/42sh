/*
** cd.c for 42sh in /home/chambo-e/Dropbox/epitech/42sh/groupe_milox/chambo_e/cd
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Mon May 12 15:25:40 2014 chambon emmanuel
** Last update Sun May 25 20:24:47 2014 chambon emmanuel
*/

#include "42.h"

int		cd_home(t_sh *sh)
{
  char		*home;

  if (!(home = get_item(sh, "HOME=")))
    return (-1);
  if (chdir(home))
    {
      perror("cd :");
      free(home);
      return (-1);
    }
  free(home);
  return (0);
}

void		set_env_cd(char *oldpwd, t_sh *sh)
{
  char		newpwd[1024];

  bzero(&newpwd, 1024);
  if (!(getcwd(newpwd, sizeof(newpwd))))
    {
      perror("cd :");
      return ;
    }
  if ((add_item("OLDPWD", oldpwd, sh))
      || (add_item("PWD", newpwd, sh)))
    return ;
}

int		cd_oldpwd(t_sh *sh)
{
  char		*oldpwd;

  if (!(oldpwd = get_item(sh, "OLDPWD=")))
    return (-1);
  if (chdir(oldpwd) == -1)
    {
      perror("cd");
      return (-1);
    }
  printf("%s\n", oldpwd);
  free(oldpwd);
  return (0);
}

int		cd_me_dat(t_sh *sh, char **opt)
{
  if (!opt[0] || !strcmp(opt[0], "--"))
    {
      if (cd_home(sh))
	{
	  sh->misc.last_return = 1;
	  return (-1);
	}
    }
  else if (opt[0][0] == '-' && strlen(opt[0]) == 1)
    {
      if (cd_oldpwd(sh) == -1)
	{
	  sh->misc.last_return = 1;
	  return (-1);
	}
    }
  else if (chdir(opt[0]))
    {
      sh->misc.last_return = 1;
      perror("cd");
      return (-1);
    }
  return (0);
}

int		cd(char **opt, t_sh *sh)
{
  char		oldpwd[1024];

  if (tab_len(opt, "cd") > 1)
    return (0);
  bzero(&oldpwd, 1024);
  if (!(getcwd(oldpwd, sizeof(oldpwd))))
    {
      sh->misc.last_return = 1;
      perror("cd");
      return (0);
    }
  if (cd_me_dat(sh, opt) == -1)
    {
      sh->misc.last_return = 1;
      return (0);
    }
  set_env_cd((char *)oldpwd, sh);
  return (0);
}
