/*
** env.c for 42sh in /home/chambo_e/Dropbox/42sh/groupe_milox/chambo_e
**
** Made by chambon emmanuel
** Login   <chambo_e@epitech.net>
**
** Started on  Tue Mar 25 13:20:37 2014 chambon emmanuel
** Last update Thu May 22 15:13:30 2014 chambon emmanuel
*/

#include "42.h"

void		print_env(char **envp, char sep)
{
  int		i;

  i = 0;
  while (envp[i])
    {
      my_putstr(envp[i]);
      my_putchar(sep);
      i++;
    }
  if (sep == '\0')
    printf("\n");
}

void		print_version_env()
{
  printf("env 0.1\nMade for 42sh - Epitech by chambo_e\n");
}

void		print_help_env()
{
  printf("Usage: env [OPTION]\n");
  printf("Without any option print the env on the screen\n\nOption:\n");
  printf("   -0, --null : \n\tend each line with a 0 byte rather than newline\n");
  printf("   --help :\n\tdisplay this help\n");
  printf("   --version :\n\tdisplay version of the command\n");
}

void		print_error_env(char *error)
{
  fprintf(stderr,
	  "env: invalid option \"%s\"\nTry \"env --help\" for more information\n"
	 , error);
}

void		my_env(char **opt, t_sh *sh)
{
  int		i;

  i = 0;
  if (opt[0] == NULL)
    print_env(sh->env, '\n');
  else
    {
      while (opt[i])
	{
	  if (!strcmp(opt[i], "-0")
	      || !strcmp(opt[i], "--null"))
	    print_env(sh->env, '\0');
	  else if (!strcmp(opt[i], "--version"))
	    print_version_env();
	  else if (!strcmp(opt[i], "--help")
		   || !strcmp(opt[i], "-h"))
	    print_help_env();
	  else
	    {
	      print_error_env(opt[i]);
	      return ;
	    }
	  i++;
	}
    }
}
